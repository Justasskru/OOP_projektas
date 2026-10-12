#include "payments/CardPayment.h"

#include <algorithm>
#include <cctype>
#include <iostream>

CardPayment::CardPayment(std::string cardNumber) : cardNumber_(std::move(cardNumber)) {}

bool CardPayment::pay(double amount) {
    if (!isValidCardNumber(cardNumber_)) {
        std::cout << "Mokejimas atmestas: neteisingas korteles numeris.\n";
        return false;
    }

    std::cout << "Korteles mokejimas patvirtintas: " << amount << " EUR\n";
    return true;
}

std::string CardPayment::getName() const {
    return "Kortele";
}

bool CardPayment::isValidCardNumber(const std::string& cardNumber) {
    return cardNumber.size() == 16
        && std::all_of(cardNumber.begin(), cardNumber.end(), [](unsigned char c) { return std::isdigit(c); });
}
