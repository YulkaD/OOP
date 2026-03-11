#include "SummaryReport.h"
#include <sstream>

std::string SummaryReport::name() const {
    return "Summary";
}

std::string SummaryReport::generate(const std::vector<Order>& orders) {
    std::ostringstream oss;
    oss << "=== SUMMARY REPORT ===\n";
    oss << "Total orders: " << orders.size() << "\n";

    double total = 0;
    int processedCount = 0;

    for (const auto& o : orders) {
        total += o.totalAmount;
        if (o.status == "processing" || o.status == "shipped" || o.status == "delivered") {
            processedCount++;
        }
    }

    oss << "Total revenue: $" << total << "\n";
    oss << "Processed orders: " << processedCount << "\n";

    return oss.str();
}