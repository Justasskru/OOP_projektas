#include "Order.h"

Order::Order() : id_(nextId_++) {}

Order::Order(int id) : id_(id) {
    if (id >= nextId_) nextId_ = id + 1;   
}

void Order::addItem(const product& product, int quantity) {
   
    for (auto& item : items_) {
        if (&item.getProduct() == &product) {
            item.increaseQuantity(quantity);
            return;
        }
    }
    items_.emplace_back(product, quantity);  
}