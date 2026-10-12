#pragma once

#include "interfaces/IDiscountStrategy.h"
#include "orders/Order.h"
#include "orders/OrderPriceCalculator.h"

class ReceiptPrinter {
public:
    void print(const Order& order, const IDiscountStrategy& discount, const OrderPriceCalculator& calculator) const;
};
