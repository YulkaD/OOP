#include <iostream>
#include <vector>
#include <memory>
#include "Order.h"
#include "Logger.h"
#include "ConfigManager.h"
#include "ReportFactory.h"
#include "OrderProcessor.h"
#include "EventDispatcher.h"
#include "StatisticsCollector.h"
#include "SummaryReport.h"
#include "DetailedReport.h"
#include "CustomerReport.h"
#include "PaymentMethodReport.h"

// Автоматична реєстрація звітів
static ReportRegistrar<SummaryReport> summaryReg("summary");
static ReportRegistrar<DetailedReport> detailedReg("detailed");
static ReportRegistrar<CustomerReport> customerReg("customer");
static ReportRegistrar<PaymentMethodReport> paymentReg("payment");

int main() {
    try {
        auto& logger = Logger::instance();
        auto& config = ConfigManager::instance();
        auto& dispatcher = EventDispatcher::instance();
        auto& stats = StatisticsCollector::instance();

        logger.info("System started");

        std::cout << "\n=== Order Processing System (Refactored) ===\n";

        // Створення тестових замовлень
        std::vector<Order> orders = {
            {1, "Alice Smith",  150.00, "new", {"Widget A", "Widget B"},
             logger.currentTime(), "", "credit_card", false},
            {2, "Bob Jones",    320.50, "new", {"Gadget X"},
             logger.currentTime(), "", "bank_transfer", true},
            {3, "Carol White",   89.99, "new", {"Doohickey", "Thingamajig"},
             logger.currentTime(), "", "cash", false},
            {4, "Dave Brown",   450.00, "new", {"Premium Package"},
             logger.currentTime(), "", "credit_card", true},
            {5, "Eve Davis",    275.25, "new", {"Multi Items A", "Multi Items B"},
             logger.currentTime(), "", "bank_transfer", false},
        };

        // Валідація замовлень
        for (auto& order : orders) {
            if (!OrderProcessor::validateOrder(order)) {
                logger.warn("Order validation failed: " + std::to_string(order.id));
            }
            else {
                stats.recordOrder(order);
            }
        }

        // Обробка замовлень
        for (auto& order : orders) {
            OrderProcessor::processOrder(order);
        }

        // Відправка деяких замовлень
        OrderProcessor::shipOrder(orders[0]);
        OrderProcessor::shipOrder(orders[2]);

        // Доставка
        OrderProcessor::deliverOrder(orders[0]);

        // Генерація звітів
        std::cout << "\n=== Generating Reports ===\n";
        std::vector<std::string> reportTypes = { "summary", "detailed", "customer", "payment" };

        for (const auto& type : reportTypes) {
            try {
                logger.info("Generating report: " + type);
                auto report = ReportFactory::instance().createReport(type);
                std::cout << "\n" << report->generate(orders) << "\n";
            }
            catch (const std::exception& e) {
                logger.error("Failed to generate report: " + std::string(e.what()));
            }
        }

        // Статистика
        std::cout << "\n=== Statistics ===\n";
        stats.printStatistics();

        logger.info("System shutdown");

    }
    catch (const std::exception& e) {
        std::cerr << "Fatal error: " << e.what() << std::endl;
        return 1;
    }

    std::cout << "\nDone. Check log files for details.\n";
    std::cout << "Press Enter to exit...";
    std::cin.get();
    return 0;
}