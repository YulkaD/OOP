#ifndef ORDER_PROCESSOR_H
#define ORDER_PROCESSOR_H

#include "Order.h"
#include <vector>

class OrderProcessor {
public:
    static bool validateOrder(const Order& order);
    static bool isValidStatus(const std::string& status);

    static double calculateTax(double amount);
    static double calculateShipping(const Order& order);
    static double calculateTotalPrice(const Order& order);

    static void processOrder(Order& order);
    static void shipOrder(Order& order);
    static void deliverOrder(Order& order);
};

#endif // ORDER_PROCESSOR_H