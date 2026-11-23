#pragma once
#include "interfaces/IDiscountStrategy.h"

class NoDiscount : public IDiscountStrategy {
public:
    double apply(double total, const Order& order) const override { return total; }
    std::string getName() const override { return "Be nuolaidos"; }
};