#pragma once

#include "orders/OrderItem.h"

#include <vector>

class Order {
public:
    Order();

    int getId() const;
    void addItem(std::shared_ptr<Product> product, int quantity);
    const std::vector<OrderItem>& getItems() const;
    bool empty() const;

private:
    int id_;
    std::vector<OrderItem> items_;

    static int nextId_;
};
