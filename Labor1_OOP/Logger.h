#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>
#include <mutex>

enum class LogLevel {
    ERROR = 0,
    WARN = 1,
    INFO = 2,
    DEBUG = 3
};

class Logger {
public:
    static Logger& instance();

    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    void error(const std::string& message);
    void warn(const std::string& message);
    void info(const std::string& message);
    void debug(const std::string& message);

    void logOrderEvent(int orderId, const std::string& event);
    void audit(const std::string& action, const std::string& details);
    void stats(const std::string& statName, double value);

    void setLogLevel(LogLevel level);
    void setDebugMode(bool enabled);

    std::string currentTime();

private:
    Logger();
    ~Logger();

    void log(LogLevel level, const std::string& message);
    std::string levelToString(LogLevel level);

    std::ofstream m_logFile;
    std::ofstream m_auditFile;
    std::ofstream m_statsFile;
    std::mutex m_mutex;
    LogLevel m_currentLevel;
    bool m_debugMode;
};

#endif // LOGGER_H