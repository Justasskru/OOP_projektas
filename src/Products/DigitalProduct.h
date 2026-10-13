#pragma once 
#include "Products.h"

class DigitalProduct : public product {
    std::string downloadUrl_;

public:
    DigitalProduct(std::string name, double price, std::string Url)
        : product(std::move(name), price), downloadUrl_(std::move(Url)) {}

    std::string getDescription() const override {
        return getName() + " (skaitmeninė prekė)";
    }
    std::string getDownloadUrl() const { return downloadUrl_; }
};
