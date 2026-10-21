#pragma once

class IShippable {
public:
    virtual ~IShippable() = default;
    virtual double getWeight() const = 0;
    virtual double calculateShippingCost() const = 0;
};