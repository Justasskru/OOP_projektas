#pragma once
#include <vector>
#include "OrderItem.h"

class Order {
    inline static int nextId_ = 1;   
    int id_;
    std::vector<OrderItem> items_;  
public:
    Order();                         
    explicit Order(int id);          

    void addItem(const product& product, int quantity);

    int getId() const { return id_; }
    bool isEmpty() const { return items_.empty(); }
    const std::vector<OrderItem>& getItems() const { return items_; }  
};