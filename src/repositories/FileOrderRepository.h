#pragma once

#include "interfaces/IOrderRepository.h"

#include <string>
#include <vector>

class FileOrderRepository : public IOrderRepository {
public:
    explicit FileOrderRepository(std::string path);

    void save(const Order& order) override;
    std::optional<Order> findById(int id) const override;
    std::vector<Order> getAll() const override;

private:
    std::string path_;
    mutable std::vector<Order> cache_;
};
