#include "LightThemeFactory.h"
#include <sstream>

std::string LightThemeFactory::createButton(const std::string& label) const {
    std::ostringstream oss;
    oss << "[LIGHT BTN: " << label << " | bg=#FFFFFF fg=#000000]";
    return oss.str();
}

std::string LightThemeFactory::createCheckbox(const std::string& label, bool checked) const {
    std::string mark = checked ? "X" : " ";
    std::ostringstream oss;
    oss << "[" << mark << "] " << label << " (light)";
    return oss.str();
}

std::string LightThemeFactory::createTextInput(const std::string& placeholder) const {
    std::ostringstream oss;
    oss << "[LIGHT INPUT: " << placeholder << "]";
    return oss.str();
}

std::string LightThemeFactory::createDropdown(const std::string& selected, const std::vector<std::string>& options) const {
    std::ostringstream oss;
    oss << "[LIGHT DROPDOWN: " << selected << "]";
    return oss.str();
}

std::string LightThemeFactory::createLabel(const std::string& text) const {
    std::ostringstream oss;
    oss << "[LIGHT LABEL: " << text << "]";
    return oss.str();
}

std::string LightThemeFactory::createRadioButton(const std::string& label, bool selected) const {
    std::string mark = selected ? "[*]" : "[ ]";
    std::ostringstream oss;
    oss << mark << " " << label << " (light)";
    return oss.str();
}

std::string LightThemeFactory::createSelect(const std::string& label, const std::vector<std::string>& options) const {
    std::ostringstream oss;
    oss << "[LIGHT SELECT: " << label << "]";
    return oss.str();
}

std::string LightThemeFactory::createProgressBar(const std::string& label, int percent) const {
    std::ostringstream oss;
    oss << "[LIGHT PROGRESS: " << label << " " << percent << "%]";
    return oss.str();
}