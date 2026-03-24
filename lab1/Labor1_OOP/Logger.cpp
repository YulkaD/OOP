#include "Logger.h"
#include <iostream>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <sstream>

Logger& Logger::instance() {
    static Logger instance;
    return instance;
}

Logger::Logger()
    : m_currentLevel(LogLevel::INFO)
    , m_debugMode(true) {

    m_logFile.open("orders.log", std::ios::app);
    m_auditFile.open("audit.log", std::ios::app);
    m_statsFile.open("statistics.log", std::ios::app);

    log(LogLevel::INFO, "Logger initialized");
}

Logger::~Logger() {
    log(LogLevel::INFO, "Logger shutting down");

    if (m_logFile.is_open()) {
        m_logFile.flush();
        m_logFile.close();
    }
    if (m_auditFile.is_open()) {
        m_auditFile.flush();
        m_auditFile.close();
    }
    if (m_statsFile.is_open()) {
        m_statsFile.flush();
        m_statsFile.close();
    }
}

std::string Logger::currentTime() {
    auto now = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(now);

    std::tm tm{};
#ifdef _WIN32
    localtime_s(&tm, &t);
#else
    localtime_r(&t, &tm);
#endif

    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

std::string Logger::levelToString(LogLevel level) {
    switch (level) {
    case LogLevel::ERROR: return "ERROR";
    case LogLevel::WARN:  return "WARN";
    case LogLevel::INFO:  return "INFO";
    case LogLevel::DEBUG: return "DEBUG";
    default: return "UNKNOWN";
    }
}

void Logger::log(LogLevel level, const std::string& message) {
    std::lock_guard<std::mutex> lock(m_mutex);

    if (static_cast<int>(level) > static_cast<int>(m_currentLevel)) {
        return;
    }

    std::string formatted = "[" + currentTime() + "] [" + levelToString(level) + "] " + message;

    if (m_logFile.is_open()) {
        m_logFile << formatted << std::endl;
        m_logFile.flush();
    }

    if (m_debugMode || level == LogLevel::ERROR) {
        std::cout << formatted << std::endl;
    }
}

void Logger::error(const std::string& message) { log(LogLevel::ERROR, message); }
void Logger::warn(const std::string& message) { log(LogLevel::WARN, message); }
void Logger::info(const std::string& message) { log(LogLevel::INFO, message); }
void Logger::debug(const std::string& message) { log(LogLevel::DEBUG, message); }

void Logger::logOrderEvent(int orderId, const std::string& event) {
    log(LogLevel::INFO, "[ORDER " + std::to_string(orderId) + "] " + event);
}

void Logger::audit(const std::string& action, const std::string& details) {
    std::lock_guard<std::mutex> lock(m_mutex);
    if (m_auditFile.is_open()) {
        m_auditFile << "[" << currentTime() << "] " << action << " | " << details << std::endl;
        m_auditFile.flush();
    }
}

void Logger::stats(const std::string& statName, double value) {
    std::lock_guard<std::mutex> lock(m_mutex);
    if (m_statsFile.is_open()) {
        m_statsFile << "[" << currentTime() << "] [STAT] " << statName << "=" << value << std::endl;
        m_statsFile.flush();
    }
}

void Logger::setLogLevel(LogLevel level) {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_currentLevel = level;
}

void Logger::setDebugMode(bool enabled) {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_debugMode = enabled;
}