#include "discounts/NoDiscount.h"
#include "discounts/PercentDiscount.h"
#include "discounts/ThreeForTwoDiscount.h"
#include "interfaces/IDiscountStrategy.h"
#include "interfaces/IPaymentMethod.h"
#include "orders/Order.h"
#include "orders/OrderPriceCalculator.h"
#include "payments/CardPayment.h"
#include "payments/CashPayment.h"
#include "payments/PayPalPayment.h"
#include "products/DigitalProduct.h"
#include "products/PhysicalProduct.h"
#include "repositories/FileOrderRepository.h"
#include "repositories/InMemoryOrderRepository.h"
#include "services/OrderService.h"
#include "services/ReceiptPrinter.h"

#include <iostream>
#include <limits>
#include <memory>
#include <vector>

namespace {

void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void printProducts(const std::vector<std::shared_ptr<Product>>& products) {
    std::cout << "\nPrekiu sarasas:\n";
    for (std::size_t i = 0; i < products.size(); ++i) {
        std::cout << i + 1 << ". " << products[i]->getName() << " - "
                  << products[i]->getPrice() << " EUR (" << products[i]->getDescription() << ")\n";
    }
}

const IDiscountStrategy& chooseDiscount(const NoDiscount& noDiscount,
                                        const PercentDiscount& studentDiscount,
                                        const ThreeForTwoDiscount& threeForTwoDiscount) {
    while (true) {
        std::cout << "\nPasirinkite nuolaida:\n"
                  << "1. Be nuolaidos\n"
                  << "2. Studento 10%\n"
                  << "3. Pirk 3 mokek 2\n"
                  << "Jusu pasirinkimas: ";

        int choice = 0;
        if (!(std::cin >> choice)) {
            clearInput();
            continue;
        }

        switch (choice) {
            case 1:
                return noDiscount;
            case 2:
                return studentDiscount;
            case 3:
                return threeForTwoDiscount;
            default:
                std::cout << "Neteisingas pasirinkimas.\n";
                break;
        }
    }
}

std::unique_ptr<IPaymentMethod> choosePaymentMethod() {
    while (true) {
        std::cout << "\nPasirinkite mokejimo buda:\n"
                  << "1. Kortele\n"
                  << "2. PayPal\n"
                  << "3. Grynieji\n"
                  << "Jusu pasirinkimas: ";

        int choice = 0;
        if (!(std::cin >> choice)) {
            clearInput();
            continue;
        }

        if (choice == 1) {
            std::string cardNumber;
            std::cout << "Iveskite 16 skaitmenu korteles numeri: ";
            std::cin >> cardNumber;
            return std::make_unique<CardPayment>(cardNumber);
        }

        if (choice == 2) {
            std::string email;
            std::cout << "Iveskite PayPal el. pasta: ";
            std::cin >> email;
            return std::make_unique<PayPalPayment>(email);
        }

        if (choice == 3) {
            double paidAmount = 0.0;
            std::cout << "Iveskite duodama suma: ";
            if (!(std::cin >> paidAmount)) {
                clearInput();
                continue;
            }
            return std::make_unique<CashPayment>(paidAmount);
        }

        std::cout << "Neteisingas pasirinkimas.\n";
    }
}

} // namespace

int main() {
    std::vector<std::shared_ptr<Product>> products = {
        std::make_shared<PhysicalProduct>("Knyga", 12.99, 0.5),
        std::make_shared<PhysicalProduct>("Ausines", 49.99, 0.3),
        std::make_shared<DigitalProduct>("E-kursas", 29.99, "https://example.com/download")
    };

    NoDiscount noDiscount;
    PercentDiscount studentDiscount(10.0);
    ThreeForTwoDiscount threeForTwoDiscount;

    ReceiptPrinter receiptPrinter;
    OrderPriceCalculator calculator;

    FileOrderRepository fileRepo("orders.csv");
    InMemoryOrderRepository memoryRepo;

    IOrderRepository* selectedRepo = &fileRepo;
    auto orderService = std::make_unique<OrderService>(*selectedRepo, calculator, receiptPrinter);

    Order currentOrder;

    bool running = true;
    while (running) {
        std::cout << "\n--- Parduotuves meniu ---\n"
                  << "1. Rodyti prekes\n"
                  << "2. Ideti i krepseli\n"
                  << "3. Keisti saugykla (File/InMemory)\n"
                  << "4. Apmoketi\n"
                  << "5. Baigti\n"
                  << "Pasirinkimas: ";

        int choice = 0;
        if (!(std::cin >> choice)) {
            clearInput();
            continue;
        }

        switch (choice) {
            case 1: {
                printProducts(products);
                break;
            }
            case 2: {
                printProducts(products);
                std::cout << "Pasirinkite prekes numeri: ";
                std::size_t productIndex = 0;
                if (!(std::cin >> productIndex) || productIndex == 0 || productIndex > products.size()) {
                    std::cout << "Neteisingas prekes numeris.\n";
                    clearInput();
                    break;
                }

                std::cout << "Kiekis: ";
                int quantity = 0;
                if (!(std::cin >> quantity)) {
                    std::cout << "Neteisingas kiekis.\n";
                    clearInput();
                    break;
                }

                try {
                    currentOrder.addItem(products[productIndex - 1], quantity);
                    std::cout << "Preke ideta i krepseli.\n";
                } catch (const std::exception& ex) {
                    std::cout << "Klaida: " << ex.what() << "\n";
                }

                break;
            }
            case 3: {
                std::cout << "Pasirinkite saugykla (1 - failas, 2 - atmintis): ";
                int repoChoice = 0;
                if (!(std::cin >> repoChoice)) {
                    clearInput();
                    break;
                }

                if (repoChoice == 1) {
                    selectedRepo = &fileRepo;
                } else if (repoChoice == 2) {
                    selectedRepo = &memoryRepo;
                } else {
                    std::cout << "Neteisingas pasirinkimas.\n";
                    break;
                }

                orderService = std::make_unique<OrderService>(*selectedRepo, calculator, receiptPrinter);
                std::cout << "Saugykla pakeista.\n";
                break;
            }
            case 4: {
                const auto& discount = chooseDiscount(noDiscount, studentDiscount, threeForTwoDiscount);
                auto payment = choosePaymentMethod();

                if (orderService->checkout(currentOrder, *payment, discount)) {
                    std::cout << "Uzsakymas sekmingai issaugotas.\n";
                    currentOrder = Order();
                } else {
                    std::cout << "Apmokejimas nepavyko.\n";
                }

                break;
            }
            case 5:
                running = false;
                break;
            default:
                std::cout << "Neteisingas pasirinkimas.\n";
                break;
        }
    }

    return 0;
}
