#include "OrderProcessor.h"
#include "Logger.h"
#include "ConfigManager.h"
#include "EventDispatcher.h"

bool OrderProcessor::validateOrder(const Order& order) {
    auto& logger = Logger::instance();

    if (order.id <= 0) {
        logger.debug("Invalid order ID: " + std::to_string(order.id));
        return false;
    }
    if (order.customerName.empty()) {
        logger.debug("Order has no customer name");
        return false;
    }
    if (order.totalAmount <= 0) {
        logger.debug("Order has invalid amount: " + std::to_string(order.totalAmount));
        return false;
    }
    if (order.items.empty()) {
        logger.debug("Order has no items");
        return false;
    }
    if (order.paymentMethod != "credit_card" &&
        order.paymentMethod != "bank_transfer" &&
        order.paymentMethod != "cash") {
        logger.debug("Invalid payment method: " + order.paymentMethod);
        return false;
    }
    return true;
}

bool OrderProcessor::isValidStatus(const std::string& status) {
    return status == "new" || status == "processing" ||
        status == "shipped" || status == "delivered";
}

double OrderProcessor::calculateTax(double amount) {
    return amount * ConfigManager::instance().taxRate();
}

double OrderProcessor::calculateShipping(const Order& order) {
    double base = ConfigManager::instance().shippingFee();

    if (order.isExpressShipping) {
        base *= 2.5;
    }
    if (order.totalAmount > 500) {
        base *= 0.5;
    }
    return base;
}

double OrderProcessor::calculateTotalPrice(const Order& order) {
    double tax = calculateTax(order.totalAmount);
    double shipping = calculateShipping(order);
    return order.totalAmount + tax + shipping;
}

void OrderProcessor::processOrder(Order& order) {
    auto& logger = Logger::instance();

    logger.info("Processing order " + std::to_string(order.id));
    logger.audit("PROCESS_START", "order_id=" + std::to_string(order.id));

    order.status = "processing";
    order.updatedAt = logger.currentTime();

    logger.logOrderEvent(order.id, "Status changed to: processing");

    double total = calculateTotalPrice(order);
    logger.info("Order " + std::to_string(order.id) + " total: $" + std::to_string(total));

    logger.audit("PROCESS_END", "status=success");

    EventDispatcher::instance().dispatch("order_processed",
        "order_id=" + std::to_string(order.id));
}

void OrderProcessor::shipOrder(Order& order) {
    auto& logger = Logger::instance();

    if (order.status != "processing") {
        logger.error("Cannot ship order " + std::to_string(order.id) + " — not processing");
        logger.audit("SHIP_FAILED", "invalid_status=" + order.status);
        return;
    }

    order.status = "shipped";
    order.updatedAt = logger.currentTime();

    logger.logOrderEvent(order.id, "Status changed to: shipped");
    logger.audit("SHIP_SUCCESS", "order_id=" + std::to_string(order.id));
}

void OrderProcessor::deliverOrder(Order& order) {
    auto& logger = Logger::instance();

    if (order.status != "shipped") {
        logger.error("Cannot deliver order " + std::to_string(order.id) + " — not shipped");
        return;
    }

    order.status = "delivered";
    order.updatedAt = logger.currentTime();

    logger.logOrderEvent(order.id, "Status changed to: delivered");
    logger.audit("DELIVERY_SUCCESS", "customer=" + order.customerName);
}