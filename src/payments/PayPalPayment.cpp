#include "payments/PayPalPayment.h"

#include <iostream>

PayPalPayment::PayPalPayment(std::string email) : email_(std::move(email)) {}

bool PayPalPayment::pay(double amount) {
    if (!isValidEmail(email_)) {
        std::cout << "Mokejimas atmestas: neteisingas PayPal el. pastas.\n";
        return false;
    }

    std::cout << "PayPal mokejimas patvirtintas: " << amount << " EUR\n";
    return true;
}

std::string PayPalPayment::getName() const {
    return "PayPal";
}

bool PayPalPayment::isValidEmail(const std::string& email) {
    const auto atPos = email.find('@');
    const auto dotPos = email.rfind('.');
    return atPos != std::string::npos && dotPos != std::string::npos && atPos < dotPos;
}
