#include "services/ReceiptPrinter.h"

#include "interfaces/IShippable.h"

#include <iomanip>
#include <iostream>

void ReceiptPrinter::print(const Order& order, const IDiscountStrategy& discount, const OrderPriceCalculator& calculator) const {
    std::cout << "\n===== CEKIS =====\n";
    std::cout << "Uzsakymo ID: " << order.getId() << "\n";

    for (const auto& item : order.getItems()) {
        std::cout << "- " << item.product->getName() << " x" << item.quantity
                  << " @ " << std::fixed << std::setprecision(2) << item.product->getPrice() << " EUR";

        if (const auto* shippable = dynamic_cast<const IShippable*>(item.product.get())) {
            std::cout << " (pristatymas: " << shippable->calculateShippingCost() * item.quantity << " EUR)";
        }

        std::cout << "\n";
    }

    const double subtotal = calculator.calculateSubtotal(order);
    const double discounted = calculator.calculateDiscountedSubtotal(order, discount);
    const double shipping = calculator.calculateShipping(order);
    const double total = calculator.calculateTotal(order, discount);

    std::cout << "Nuolaida: " << discount.getName() << "\n";
    std::cout << "Tarpine suma: " << subtotal << " EUR\n";
    std::cout << "Po nuolaidos: " << discounted << " EUR\n";
    std::cout << "Pristatymas: " << shipping << " EUR\n";
    std::cout << "Moketi: " << total << " EUR\n";
    std::cout << "=================\n\n";
}
