#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <vector>

struct Order {
    int id;
    std::string customerName;
    double totalAmount;
    std::string status;
    std::vector<std::string> items;
    std::string createdAt;
    std::string updatedAt;
    std::string paymentMethod;
    bool isExpressShipping = false;
};

#endif // ORDER_H