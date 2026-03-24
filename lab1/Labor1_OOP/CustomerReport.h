#ifndef CUSTOMER_REPORT_H
#define CUSTOMER_REPORT_H

#include "Report.h"
#include <string>
#include <vector>

class CustomerReport : public Report {
public:
    std::string name() const override;
    std::string generate(const std::vector<Order>& orders) override;
};

#endif // CUSTOMER_REPORT_H