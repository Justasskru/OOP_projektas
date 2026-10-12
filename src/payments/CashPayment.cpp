#include "payments/CashPayment.h"

#include <iostream>

CashPayment::CashPayment(double paidAmount) : paidAmount_(paidAmount) {}

bool CashPayment::pay(double amount) {
    if (paidAmount_ < amount) {
        std::cout << "Mokejimas atmestas: nepakankamai grynuju.\n";
        return false;
    }

    std::cout << "Grynuju mokejimas patvirtintas: " << amount << " EUR\n";
    std::cout << "Graza: " << (paidAmount_ - amount) << " EUR\n";
    return true;
}

std::string CashPayment::getName() const {
    return "Grynieji";
}
