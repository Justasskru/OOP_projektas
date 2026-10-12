#include "products/DigitalProduct.h"

DigitalProduct::DigitalProduct(std::string name, double price, std::string downloadUrl)
    : Product(std::move(name), price), downloadUrl_(std::move(downloadUrl)) {}

std::string DigitalProduct::getDescription() const {
    return "Skaitmenine preke";
}

const std::string& DigitalProduct::getDownloadUrl() const {
    return downloadUrl_;
}
