#include "CompactThemeFactory.h"
#include <sstream>

std::string CompactThemeFactory::createButton(const std::string& label) const {
    std::ostringstream oss;
    oss << "[COMPACT BTN: " << label << " | minimal]";
    return oss.str();
}

std::string CompactThemeFactory::createCheckbox(const std::string& label, bool checked) const {
    std::string mark = checked ? "[X]" : "[ ]";
    std::ostringstream oss;
    oss << mark << " " << label << " (compact)";
    return oss.str();
}

std::string CompactThemeFactory::createTextInput(const std::string& placeholder) const {
    std::ostringstream oss;
    oss << "[COMPACT INPUT: " << placeholder << "]";
    return oss.str();
}

std::string CompactThemeFactory::createDropdown(const std::string& selected, const std::vector<std::string>& options) const {
    std::ostringstream oss;
    oss << "[COMPACT DROPDOWN: " << selected << "]";
    return oss.str();
}

std::string CompactThemeFactory::createLabel(const std::string& text) const {
    std::ostringstream oss;
    oss << "[COMPACT LABEL: " << text << "]";
    return oss.str();
}

std::string CompactThemeFactory::createRadioButton(const std::string& label, bool selected) const {
    std::string mark = selected ? "(*)" : "( )";
    std::ostringstream oss;
    oss << mark << " " << label << " (compact)";
    return oss.str();
}

std::string CompactThemeFactory::createSelect(const std::string& label, const std::vector<std::string>& options) const {
    std::ostringstream oss;
    oss << "[COMPACT SELECT: " << label << "]";
    return oss.str();
}

std::string CompactThemeFactory::createProgressBar(const std::string& label, int percent) const {
    std::ostringstream oss;
    oss << "[COMPACT PROGRESS: " << label << " " << percent << "%]";
    return oss.str();
}