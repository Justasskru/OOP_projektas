#pragma once

#include "interfaces/IDiscountStrategy.h"
#include "orders/Order.h"

class OrderPriceCalculator {
public:
    double calculateSubtotal(const Order& order) const;
    double calculateShipping(const Order& order) const;
    double calculateDiscountedSubtotal(const Order& order, const IDiscountStrategy& discount) const;
    double calculateTotal(const Order& order, const IDiscountStrategy& discount) const;
};
