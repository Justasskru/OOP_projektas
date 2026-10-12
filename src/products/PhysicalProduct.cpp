#include "products/PhysicalProduct.h"

#include <sstream>

PhysicalProduct::PhysicalProduct(std::string name, double price, double weightKg)
    : Product(std::move(name), price), weightKg_(weightKg) {}

std::string PhysicalProduct::getDescription() const {
    std::ostringstream out;
    out << "Fizine preke (" << weightKg_ << " kg)";
    return out.str();
}

double PhysicalProduct::getWeight() const {
    return weightKg_;
}

double PhysicalProduct::calculateShippingCost() const {
    return 1.25 * weightKg_;
}
