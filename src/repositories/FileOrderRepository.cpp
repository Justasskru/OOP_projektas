#include "repositories/FileOrderRepository.h"

#include "orders/Order.h"

#include <fstream>

FileOrderRepository::FileOrderRepository(std::string path) : path_(std::move(path)) {}

void FileOrderRepository::save(const Order& order) {
    cache_.push_back(order);

    std::ofstream file(path_, std::ios::app);
    if (!file) {
        return;
    }

    file << order.getId();
    for (const auto& item : order.getItems()) {
        file << ',' << item.product->getName() << ':' << item.quantity;
    }
    file << '\n';
}

std::optional<Order> FileOrderRepository::findById(int id) const {
    for (const auto& order : cache_) {
        if (order.getId() == id) {
            return order;
        }
    }

    return std::nullopt;
}

std::vector<Order> FileOrderRepository::getAll() const {
    return cache_;
}
