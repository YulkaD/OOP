#include "NordThemeFactory.h"
#include <sstream>

std::string NordThemeFactory::createButton(const std::string& label) const {
    std::ostringstream oss;
    oss << "[NORD BTN: " << label << " | bg=#2E3440 fg=#ECEFF4]";
    return oss.str();
}

std::string NordThemeFactory::createCheckbox(const std::string& label, bool checked) const {
    std::string mark = checked ? "X" : " ";
    std::ostringstream oss;
    oss << "[" << mark << "] " << label << " (nord)";
    return oss.str();
}

std::string NordThemeFactory::createTextInput(const std::string& placeholder) const {
    std::ostringstream oss;
    oss << "[NORD INPUT: " << placeholder << "]";
    return oss.str();
}

std::string NordThemeFactory::createDropdown(const std::string& selected, const std::vector<std::string>& options) const {
    std::ostringstream oss;
    oss << "[NORD DROPDOWN: " << selected << "]";
    return oss.str();
}

std::string NordThemeFactory::createLabel(const std::string& text) const {
    std::ostringstream oss;
    oss << "[NORD LABEL: " << text << "]";
    return oss.str();
}

std::string NordThemeFactory::createRadioButton(const std::string& label, bool selected) const {
    std::string mark = selected ? "●" : "○";
    std::ostringstream oss;
    oss << mark << " " << label << " (nord)";
    return oss.str();
}

std::string NordThemeFactory::createSelect(const std::string& label, const std::vector<std::string>& options) const {
    std::ostringstream oss;
    oss << "[NORD SELECT: " << label << "]";
    return oss.str();
}

std::string NordThemeFactory::createProgressBar(const std::string& label, int percent) const {
    std::ostringstream oss;
    oss << "[NORD PROGRESS: " << label << " " << percent << "%]";
    return oss.str();
}