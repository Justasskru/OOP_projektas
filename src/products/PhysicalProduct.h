#pragma once

#include "interfaces/IShippable.h"
#include "products/Product.h"

#include <string>

class PhysicalProduct : public Product, public IShippable {
public:
    PhysicalProduct(std::string name, double price, double weightKg);

    std::string getDescription() const override;
    double getWeight() const override;
    double calculateShippingCost() const override;

private:
    double weightKg_;
};
