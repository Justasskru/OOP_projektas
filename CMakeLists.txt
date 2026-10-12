cmake_minimum_required(VERSION 3.16)
project(shop LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(shop
    src/main.cpp
    src/products/PhysicalProduct.cpp
    src/products/DigitalProduct.cpp
    src/payments/CardPayment.cpp
    src/payments/PayPalPayment.cpp
    src/payments/CashPayment.cpp
    src/orders/Order.cpp
    src/orders/OrderPriceCalculator.cpp
    src/repositories/InMemoryOrderRepository.cpp
    src/repositories/FileOrderRepository.cpp
    src/services/OrderService.cpp
    src/services/ReceiptPrinter.cpp
)

target_include_directories(shop PRIVATE src)
