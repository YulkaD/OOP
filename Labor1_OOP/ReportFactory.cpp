#include "ReportFactory.h"

ReportFactory& ReportFactory::instance() {
    static ReportFactory instance;
    return instance;
}

void ReportFactory::registerReport(const std::string& type, ReportCreator creator) {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_creators[type] = creator;
}

std::unique_ptr<Report> ReportFactory::createReport(const std::string& type) {
    std::lock_guard<std::mutex> lock(m_mutex);

    auto it = m_creators.find(type);
    if (it == m_creators.end()) {
        throw UnknownReportTypeException(type);
    }

    return it->second();
}

std::vector<std::string> ReportFactory::getAvailableTypes() const {
    std::lock_guard<std::mutex> lock(m_mutex);

    std::vector<std::string> types;
    types.reserve(m_creators.size());

    for (const auto& pair : m_creators) {
        types.push_back(pair.first);
    }

    return types;
}