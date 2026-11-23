#pragma once
#include "interfaces/IDiscountStrategy.h"
#include "orders/Order.h"

class ThreeForTwoDiscount : public IDiscountStrategy {
public:
    double apply(double total, const Order& order) const override {
        double discount = 0.0;
        for (const auto& item : order.getItems()) {
            int freeUnits = item.getQuantity() / 3;          // kas trečias nemokamas
            discount += freeUnits * item.getProduct().getPrice();
        }
        return total - discount;
    }
    std::string getName() const override { return "Pirk 3, mokėk 2"; }
};