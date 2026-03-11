#include "PaymentMethodReport.h"
#include <sstream>
#include <map>

std::string PaymentMethodReport::name() const {
    return "PaymentMethod";
}

std::string PaymentMethodReport::generate(const std::vector<Order>& orders) {
    std::ostringstream oss;
    oss << "=== PAYMENT METHOD REPORT ===\n";

    std::map<std::string, double> methodTotals;
    std::map<std::string, int> methodCounts;

    for (const auto& o : orders) {
        methodTotals[o.paymentMethod] += o.totalAmount;
        methodCounts[o.paymentMethod]++;
    }

    for (const auto& [method, total] : methodTotals) {
        oss << method << ": $" << total << " (" << methodCounts[method] << " orders)\n";
    }

    return oss.str();
}