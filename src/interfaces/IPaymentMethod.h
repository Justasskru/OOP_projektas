#pragma once

#include <string>

class IPaymentMethod {
public:
    virtual ~IPaymentMethod() = default;
    virtual bool pay(double amount) = 0;
    virtual std::string getName() const = 0;
};
