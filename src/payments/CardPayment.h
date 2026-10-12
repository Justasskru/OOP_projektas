#pragma once

#include "interfaces/IPaymentMethod.h"

#include <string>

class CardPayment : public IPaymentMethod {
public:
    explicit CardPayment(std::string cardNumber);

    bool pay(double amount) override;
    std::string getName() const override;

private:
    std::string cardNumber_;
    static bool isValidCardNumber(const std::string& cardNumber);
};
