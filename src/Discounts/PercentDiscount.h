#pragma once
#include <stdexcept>
#include "interfaces/IDiscountStrategy.h"

class PercentDiscount : public IDiscountStrategy {
    double percent_;
    std::string label_;
public:
    PercentDiscount(double percent, std::string label)
        : percent_(percent), label_(std::move(label)) {
        if (percent < 0 || percent > 100)
            throw std::invalid_argument("Procentas turi būti tarp 0 ir 100");
    }

    double apply(double total, const Order&) const override {
        return total * (1.0 - percent_ / 100.0);
    }
    std::string getName() const override {
        return label_ + " (-" + std::to_string(static_cast<int>(percent_)) + " %)";
    }
};