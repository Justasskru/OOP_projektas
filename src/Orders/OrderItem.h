#pragma once
#include <stdexcept>
#include "Products/Products.h"

class OrderItem {
    const product* product_;  
    int quantity_;
public:
    OrderItem(const product& product, int quantity)
        : product_(&product), quantity_(quantity) {
        if (quantity <= 0)
            throw std::invalid_argument("Kiekis turi būti didesnis už 0");
    }

    const product& getProduct() const { return *product_; }
    int getQuantity() const { return quantity_; }

    void increaseQuantity(int amount) {
        if (amount <= 0)
            throw std::invalid_argument("Kiekio padidinimas turi būti teigiamas");
        quantity_ += amount;
    }
};