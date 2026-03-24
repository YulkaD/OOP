#ifndef PAYMENT_METHOD_REPORT_H
#define PAYMENT_METHOD_REPORT_H

#include "Report.h"
#include <string>
#include <vector>

class PaymentMethodReport : public Report {
public:
    std::string name() const override;
    std::string generate(const std::vector<Order>& orders) override;
};

#endif // PAYMENT_METHOD_REPORT_H