#pragma once

class Order;

class IDiscountStrategy {
public:
    virtual ~IDiscountStrategy() = default;
    virtual double apply(double total, const Order& order) const = 0;
    virtual const char* getName() const = 0;
};
