#pragma once

#include "products/Product.h"

#include <string>

class DigitalProduct : public Product {
public:
    DigitalProduct(std::string name, double price, std::string downloadUrl);

    std::string getDescription() const override;
    const std::string& getDownloadUrl() const;

private:
    std::string downloadUrl_;
};
