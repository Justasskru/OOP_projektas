#include "services/OrderService.h"

#include <iostream>

OrderService::OrderService(IOrderRepository& repo, OrderPriceCalculator calculator, ReceiptPrinter& receiptPrinter)
    : repo_(repo), calculator_(std::move(calculator)), receiptPrinter_(receiptPrinter) {}

bool OrderService::checkout(Order& order, IPaymentMethod& payment, const IDiscountStrategy& discount) {
    if (order.empty()) {
        std::cout << "Negalima apmoketi tuscio krepselio.\n";
        return false;
    }

    const double total = calculator_.calculateTotal(order, discount);
    if (!payment.pay(total)) {
        return false;
    }

    repo_.save(order);
    receiptPrinter_.print(order, discount, calculator_);
    return true;
}
