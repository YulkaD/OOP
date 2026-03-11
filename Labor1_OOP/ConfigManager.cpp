#include "ConfigManager.h"

ConfigManager& ConfigManager::instance() {
    static ConfigManager instance;
    return instance;
}

ConfigManager::ConfigManager() {
    loadConfig();
}

void ConfigManager::loadConfig() {
    std::lock_guard<std::mutex> lock(m_mutex);

    m_config.logFile = "orders.log";
    m_config.auditFile = "audit.log";
    m_config.statsFile = "statistics.log";
    m_config.reportDir = "./reports/";
    m_config.debugMode = true;
    m_config.taxRate = 0.20;
    m_config.shippingFee = 10.0;
    m_config.logLevel = 2;
}

void ConfigManager::reloadConfig() {
    loadConfig();
}

const AppConfig& ConfigManager::getConfig() const {
    std::lock_guard<std::mutex> lock(m_mutex);
    return m_config;
}

double ConfigManager::taxRate() const {
    std::lock_guard<std::mutex> lock(m_mutex);
    return m_config.taxRate;
}

double ConfigManager::shippingFee() const {
    std::lock_guard<std::mutex> lock(m_mutex);
    return m_config.shippingFee;
}

bool ConfigManager::debugMode() const {
    std::lock_guard<std::mutex> lock(m_mutex);
    return m_config.debugMode;
}

int ConfigManager::logLevel() const {
    std::lock_guard<std::mutex> lock(m_mutex);
    return m_config.logLevel;
}

std::string ConfigManager::reportDir() const {
    std::lock_guard<std::mutex> lock(m_mutex);
    return m_config.reportDir;
}