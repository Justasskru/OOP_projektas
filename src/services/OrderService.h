#pragma once

#include "interfaces/IDiscountStrategy.h"
#include "interfaces/IOrderRepository.h"
#include "interfaces/IPaymentMethod.h"
#include "orders/Order.h"
#include "orders/OrderPriceCalculator.h"
#include "services/ReceiptPrinter.h"

class OrderService {
public:
    OrderService(IOrderRepository& repo, OrderPriceCalculator calculator, ReceiptPrinter& receiptPrinter);

    bool checkout(Order& order, IPaymentMethod& payment, const IDiscountStrategy& discount);

private:
    IOrderRepository& repo_;
    OrderPriceCalculator calculator_;
    ReceiptPrinter& receiptPrinter_;
};
