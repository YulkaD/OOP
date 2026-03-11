#ifndef STATISTICS_COLLECTOR_H
#define STATISTICS_COLLECTOR_H

#include "Order.h"
#include <string>
#include <vector>
#include <map>
#include <mutex>

class StatisticsCollector {
public:
    static StatisticsCollector& instance();

    StatisticsCollector(const StatisticsCollector&) = delete;
    StatisticsCollector& operator=(const StatisticsCollector&) = delete;

    void recordOrder(const Order& order);
    void recordEvent(const std::string& event);
    void printStatistics() const;

    int getTotalOrders() const;
    double getTotalRevenue() const;
    size_t getEventsCount() const;

private:
    StatisticsCollector();

    mutable std::mutex m_mutex;
    int m_totalOrders;
    double m_totalRevenue;
    std::vector<std::string> m_events;
    std::map<std::string, double> m_paymentMethodTotals;
    std::map<std::string, int> m_paymentMethodCounts;
};

#endif // STATISTICS_COLLECTOR_H