#ifndef REPORT_H
#define REPORT_H

#include <string>
#include <vector>
#include "Order.h"

class Report {
public:
    virtual ~Report() = default;
    virtual std::string name() const = 0;
    virtual std::string generate(const std::vector<Order>& orders) = 0;
};

#endif // REPORT_H