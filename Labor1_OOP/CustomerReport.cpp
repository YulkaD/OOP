#include "CustomerReport.h"
#include <sstream>
#include <map>

std::string CustomerReport::name() const {
    return "Customer";
}

std::string CustomerReport::generate(const std::vector<Order>& orders) {
    std::ostringstream oss;
    oss << "=== CUSTOMER REPORT ===\n";

    std::map<std::string, double> customerTotals;
    std::map<std::string, int> customerOrderCount;

    for (const auto& o : orders) {
        customerTotals[o.customerName] += o.totalAmount;
        customerOrderCount[o.customerName]++;
    }

    for (const auto& [name, total] : customerTotals) {
        oss << name << ": $" << total << " (" << customerOrderCount[name] << " orders)\n";
    }

    return oss.str();
}