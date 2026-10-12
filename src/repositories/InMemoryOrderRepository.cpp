#include "repositories/InMemoryOrderRepository.h"

void InMemoryOrderRepository::save(const Order& order) {
    orders_.push_back(order);
}

std::optional<Order> InMemoryOrderRepository::findById(int id) const {
    for (const auto& order : orders_) {
        if (order.getId() == id) {
            return order;
        }
    }

    return std::nullopt;
}

std::vector<Order> InMemoryOrderRepository::getAll() const {
    return orders_;
}
