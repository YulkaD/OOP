#include "HighContrastThemeFactory.h"
#include <sstream>

std::string HighContrastThemeFactory::createButton(const std::string& label) const {
    std::ostringstream oss;
    oss << "[HC BTN: " << label << " | bg=#FFFF00 fg=#000000]";
    return oss.str();
}

std::string HighContrastThemeFactory::createCheckbox(const std::string& label, bool checked) const {
    std::string mark = checked ? "X" : " ";
    std::ostringstream oss;
    oss << "[" << mark << "] " << label << " (high contrast)";
    return oss.str();
}

std::string HighContrastThemeFactory::createTextInput(const std::string& placeholder) const {
    std::ostringstream oss;
    oss << "[HC INPUT: " << placeholder << "]";
    return oss.str();
}

std::string HighContrastThemeFactory::createDropdown(const std::string& selected, const std::vector<std::string>& options) const {
    std::ostringstream oss;
    oss << "[HC DROPDOWN: " << selected << "]";
    return oss.str();
}

std::string HighContrastThemeFactory::createLabel(const std::string& text) const {
    std::ostringstream oss;
    oss << "[HC LABEL: " << text << "]";
    return oss.str();
}

std::string HighContrastThemeFactory::createRadioButton(const std::string& label, bool selected) const {
    std::string mark = selected ? "●" : "○";
    std::ostringstream oss;
    oss << mark << " " << label << " (high contrast)";
    return oss.str();
}

std::string HighContrastThemeFactory::createSelect(const std::string& label, const std::vector<std::string>& options) const {
    std::ostringstream oss;
    oss << "[HC SELECT: " << label << "]";
    return oss.str();
}

std::string HighContrastThemeFactory::createProgressBar(const std::string& label, int percent) const {
    std::ostringstream oss;
    oss << "[HC PROGRESS: " << label << " " << percent << "%]";
    return oss.str();
}