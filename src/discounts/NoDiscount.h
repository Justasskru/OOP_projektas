#pragma once

#include "interfaces/IDiscountStrategy.h"

class NoDiscount : public IDiscountStrategy {
public:
    double apply(double total, const Order&) const override {
        return total;
    }

    const char* getName() const override {
        return "Be nuolaidos";
    }
};
