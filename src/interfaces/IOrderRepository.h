#pragma once

#include <optional>
#include <vector>

class Order;

class IOrderRepository {
public:
    virtual ~IOrderRepository() = default;
    virtual void save(const Order& order) = 0;
    virtual std::optional<Order> findById(int id) const = 0;
    virtual std::vector<Order> getAll() const = 0;
};
