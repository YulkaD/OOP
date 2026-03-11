#include "StatisticsCollector.h"
#include "Logger.h"
#include <iostream>
#include <iomanip>

StatisticsCollector& StatisticsCollector::instance() {
    static StatisticsCollector instance;
    return instance;
}

StatisticsCollector::StatisticsCollector()
    : m_totalOrders(0)
    , m_totalRevenue(0.0) {
}

void StatisticsCollector::recordOrder(const Order& order) {
    std::lock_guard<std::mutex> lock(m_mutex);

    m_totalOrders++;
    m_totalRevenue += order.totalAmount;

    m_paymentMethodTotals[order.paymentMethod] += order.totalAmount;
    m_paymentMethodCounts[order.paymentMethod]++;
}

void StatisticsCollector::recordEvent(const std::string& event) {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_events.push_back(event);
}

void StatisticsCollector::printStatistics() const {
    std::lock_guard<std::mutex> lock(m_mutex);

    std::cout << "Total processed: " << m_totalOrders << "\n";
    std::cout << "Total revenue: $" << std::fixed << std::setprecision(2) << m_totalRevenue << "\n";
    std::cout << "Events logged: " << m_events.size() << "\n";
}

int StatisticsCollector::getTotalOrders() const {
    std::lock_guard<std::mutex> lock(m_mutex);
    return m_totalOrders;
}

double StatisticsCollector::getTotalRevenue() const {
    std::lock_guard<std::mutex> lock(m_mutex);
    return m_totalRevenue;
}

size_t StatisticsCollector::getEventsCount() const {
    std::lock_guard<std::mutex> lock(m_mutex);
    return m_events.size();
}