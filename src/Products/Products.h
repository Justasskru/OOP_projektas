#pragma once 
#include <string>
#include <utility>

class product {
    std::string name_;
    double price_;

public:
    product(std::string name, double price) 
    : name_(std::move(name)), price_(price) {}
    virtual ~product() = default;

    std::string getName() const { return name_; }
    double getPrice() const { return price_; }

    virtual std::string getDescription() const=0;
    

};