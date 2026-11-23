#pragma once
#include <string>

class Order;

class IDiscountStrategy {
public:
    virtual ~IDiscountStrategy() = default;

   virtual double apply(double total, const Order& order) const = 0;
    virtual std::string getName() const = 0;

};