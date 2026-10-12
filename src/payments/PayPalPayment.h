#pragma once

#include "interfaces/IPaymentMethod.h"

#include <string>

class PayPalPayment : public IPaymentMethod {
public:
    explicit PayPalPayment(std::string email);

    bool pay(double amount) override;
    std::string getName() const override;

private:
    std::string email_;
    static bool isValidEmail(const std::string& email);
};
