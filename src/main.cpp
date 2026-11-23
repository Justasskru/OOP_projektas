#include <iostream>
#include <memory>
#include <vector>
#include "products/PhysicalProduct.h"
#include "products/DigitalProduct.h"

int main() {
    std::vector<std::unique_ptr<product>> products;
    products.push_back(std::make_unique<PhysicalProduct>("Knyga", 12.5, 0.4));
    products.push_back(std::make_unique<DigitalProduct>("E-knyga", 7.0, "https://x.lt/a"));

    for (const auto& p : products)
        std::cout << p->getDescription() << " - " << p->getPrice() << " EUR\n";
}