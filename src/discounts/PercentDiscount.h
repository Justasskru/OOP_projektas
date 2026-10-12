#pragma once

#include "interfaces/IDiscountStrategy.h"

class PercentDiscount : public IDiscountStrategy {
public:
    explicit PercentDiscount(double percent) : percent_(percent) {}

    double apply(double total, const Order&) const override {
        return total * (1.0 - percent_ / 100.0);
    }

    const char* getName() const override {
        return "Studento 10%";
    }

private:
    double percent_;
};
