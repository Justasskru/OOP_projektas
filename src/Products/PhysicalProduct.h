#pragma once
#include "Products.h"
#include "interfaces/IShippable.h"

class PhysicalProduct : public product, public IShippable {
    double weight_;
public:
    PhysicalProduct(std::string name, double price, double weight)
        : product(std::move(name), price), weight_(weight) {}

    std::string getDescription() const override {
        return getName() + " (fizinė prekė, " + std::to_string(weight_) + " kg)";
    }
    double getWeight() const override { return weight_; }
    double calculateShippingCost() const override { return 2.0 + weight_ * 1.5; }
};