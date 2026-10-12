#include "orders/Order.h"

#include <stdexcept>

int Order::nextId_ = 1;

Order::Order() : id_(nextId_++) {}

int Order::getId() const {
    return id_;
}

void Order::addItem(std::shared_ptr<Product> product, int quantity) {
    if (!product) {
        throw std::invalid_argument("Product cannot be null");
    }

    if (quantity <= 0) {
        throw std::invalid_argument("Quantity must be positive");
    }

    items_.push_back({std::move(product), quantity});
}

const std::vector<OrderItem>& Order::getItems() const {
    return items_;
}

bool Order::empty() const {
    return items_.empty();
}
