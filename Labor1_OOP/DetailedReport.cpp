#include "DetailedReport.h"
#include <sstream>

std::string DetailedReport::name() const {
    return "Detailed";
}

std::string DetailedReport::generate(const std::vector<Order>& orders) {
    std::ostringstream oss;
    oss << "=== DETAILED REPORT ===\n";

    for (const auto& o : orders) {
        oss << "Order #" << o.id << " | " << o.customerName
            << " | $" << o.totalAmount << " | " << o.status
            << " | " << o.paymentMethod << "\n";

        for (const auto& item : o.items) {
            oss << "  - " << item << "\n";
        }

        oss << "  Created: " << o.createdAt << "\n";
    }

    return oss.str();
}