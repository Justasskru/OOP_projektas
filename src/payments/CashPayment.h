#pragma once

#include "interfaces/IPaymentMethod.h"

class CashPayment : public IPaymentMethod {
public:
    explicit CashPayment(double paidAmount);

    bool pay(double amount) override;
    std::string getName() const override;

private:
    double paidAmount_;
};
