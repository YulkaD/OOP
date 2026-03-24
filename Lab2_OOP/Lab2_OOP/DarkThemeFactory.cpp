#include "DarkThemeFactory.h"
#include <sstream>

std::string DarkThemeFactory::createButton(const std::string& label) const {
    std::ostringstream oss;
    oss << "[DARK BTN: " << label << " | bg=#1E1E1E fg=#FFFFFF]";
    return oss.str();
}

std::string DarkThemeFactory::createCheckbox(const std::string& label, bool checked) const {
    std::string mark = checked ? "X" : " ";
    std::ostringstream oss;
    oss << "[" << mark << "] " << label << " (dark)";
    return oss.str();
}

std::string DarkThemeFactory::createTextInput(const std::string& placeholder) const {
    std::ostringstream oss;
    oss << "[DARK INPUT: " << placeholder << "]";
    return oss.str();
}

std::string DarkThemeFactory::createDropdown(const std::string& selected, const std::vector<std::string>& options) const {
    std::ostringstream oss;
    oss << "[DARK DROPDOWN: " << selected << "]";
    return oss.str();
}

std::string DarkThemeFactory::createLabel(const std::string& text) const {
    std::ostringstream oss;
    oss << "[DARK LABEL: " << text << "]";
    return oss.str();
}

std::string DarkThemeFactory::createRadioButton(const std::string& label, bool selected) const {
    std::string mark = selected ? "[*]" : "[ ]";
    std::ostringstream oss;
    oss << mark << " " << label << " (dark)";
    return oss.str();
}

std::string DarkThemeFactory::createSelect(const std::string& label, const std::vector<std::string>& options) const {
    std::ostringstream oss;
    oss << "[DARK SELECT: " << label << "]";
    return oss.str();
}

std::string DarkThemeFactory::createProgressBar(const std::string& label, int percent) const {
    std::ostringstream oss;
    oss << "[DARK PROGRESS: " << label << " " << percent << "%]";
    return oss.str();
}