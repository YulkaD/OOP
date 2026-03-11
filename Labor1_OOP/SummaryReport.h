#ifndef SUMMARY_REPORT_H
#define SUMMARY_REPORT_H

#include "Report.h"
#include <string>
#include <vector>

class SummaryReport : public Report {
public:
    std::string name() const override;
    std::string generate(const std::vector<Order>& orders) override;
};

#endif // SUMMARY_REPORT_H