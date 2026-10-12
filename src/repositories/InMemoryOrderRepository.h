#pragma once

#include "interfaces/IOrderRepository.h"
#include "orders/Order.h"

#include <vector>

class InMemoryOrderRepository : public IOrderRepository {
public:
    void save(const Order& order) override;
    std::optional<Order> findById(int id) const override;
    std::vector<Order> getAll() const override;

private:
    std::vector<Order> orders_;
};
