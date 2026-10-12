#pragma once

#include "products/Product.h"

#include <memory>

struct OrderItem {
    std::shared_ptr<Product> product;
    int quantity;
};
