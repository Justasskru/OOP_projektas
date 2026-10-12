#include "orders/OrderPriceCalculator.h"

#include "interfaces/IShippable.h"

double OrderPriceCalculator::calculateSubtotal(const Order& order) const {
    double subtotal = 0.0;
    for (const auto& item : order.getItems()) {
        subtotal += item.product->getPrice() * item.quantity;
    }

    return subtotal;
}

double OrderPriceCalculator::calculateShipping(const Order& order) const {
    double shipping = 0.0;
    for (const auto& item : order.getItems()) {
        if (const auto* shippable = dynamic_cast<const IShippable*>(item.product.get())) {
            shipping += shippable->calculateShippingCost() * item.quantity;
        }
    }

    return shipping;
}

double OrderPriceCalculator::calculateDiscountedSubtotal(const Order& order, const IDiscountStrategy& discount) const {
    const double subtotal = calculateSubtotal(order);
    return discount.apply(subtotal, order);
}

double OrderPriceCalculator::calculateTotal(const Order& order, const IDiscountStrategy& discount) const {
    return calculateDiscountedSubtotal(order, discount) + calculateShipping(order);
}
