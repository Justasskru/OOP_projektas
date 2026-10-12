#pragma once

#include "interfaces/IDiscountStrategy.h"
#include "orders/Order.h"

#include <algorithm>

class ThreeForTwoDiscount : public IDiscountStrategy {
public:
    double apply(double total, const Order& order) const override {
        double discount = 0.0;
        for (const auto& item : order.getItems()) {
            const int freeItems = std::max(0, item.quantity / 3);
            discount += freeItems * item.product->getPrice();
        }

        return std::max(0.0, total - discount);
    }

    const char* getName() const override {
        return "Pirk 3 mokek 2";
    }
};
