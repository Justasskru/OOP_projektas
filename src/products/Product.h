#pragma once

#include <string>
#include <utility>

class Product {
private:
    std::string name_;
    double price_;

public:
    Product(std::string name, double price) : name_(std::move(name)), price_(price) {}
    virtual ~Product() = default;

    const std::string& getName() const { return name_; }
    double getPrice() const { return price_; }

    virtual std::string getDescription() const = 0;
};
