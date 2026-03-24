#ifndef REPORT_FACTORY_H
#define REPORT_FACTORY_H

#include "Report.h"
#include <string>
#include <memory>
#include <map>
#include <functional>
#include <stdexcept>
#include <mutex>

using ReportCreator = std::unique_ptr<Report>(*)();

class ReportFactory {
public:
    static ReportFactory& instance();

    void registerReport(const std::string& type, ReportCreator creator);

    std::unique_ptr<Report> createReport(const std::string& type);
    std::vector<std::string> getAvailableTypes() const;

private:
    ReportFactory() = default;

    std::map<std::string, ReportCreator> m_creators;
    mutable std::mutex m_mutex;
};

class UnknownReportTypeException : public std::runtime_error {
public:
    explicit UnknownReportTypeException(const std::string& type)
        : std::runtime_error("Unknown report type: " + type) {}
};

template<typename T>
class ReportRegistrar {
public:
    explicit ReportRegistrar(const std::string& type) {
        ReportFactory::instance().registerReport(type, []() -> std::unique_ptr<Report> {
            return std::make_unique<T>();
            });
    }
};

#endif // REPORT_FACTORY_H