#ifndef DETAILED_REPORT_H
#define DETAILED_REPORT_H

#include "Report.h"
#include <string>
#include <vector>

class DetailedReport : public Report {
public:
    std::string name() const override;
    std::string generate(const std::vector<Order>& orders) override;
};

#endif // DETAILED_REPORT_H