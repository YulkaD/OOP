#ifndef CONFIG_MANAGER_H
#define CONFIG_MANAGER_H

#include <string>
#include <mutex>

struct AppConfig {
    std::string logFile = "orders.log";
    std::string auditFile = "audit.log";
    std::string statsFile = "statistics.log";
    std::string reportDir = "./reports/";
    bool debugMode = true;
    double taxRate = 0.20;
    double shippingFee = 10.0;
    int logLevel = 2;
};

class ConfigManager {
public:
    static ConfigManager& instance();

    ConfigManager(const ConfigManager&) = delete;
    ConfigManager& operator=(const ConfigManager&) = delete;

    const AppConfig& getConfig() const;
    void reloadConfig();

    double taxRate() const;
    double shippingFee() const;
    bool debugMode() const;
    int logLevel() const;
    std::string reportDir() const;

private:
    ConfigManager();
    void loadConfig();

    mutable std::mutex m_mutex;
    AppConfig m_config;
};

#endif // CONFIG_MANAGER_H