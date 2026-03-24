#include "SepiaThemeFactory.h"
#include <sstream>

std::string SepiaThemeFactory::createButton(const std::string& label) const {
    std::ostringstream oss;
    oss << "[SEPIA BTN: " << label << " | bg=#F4EAD5 fg=#5C4033]";
    return oss.str();
}

std::string SepiaThemeFactory::createCheckbox(const std::string& label, bool checked) const {
    std::string mark = checked ? "X" : " ";
    std::ostringstream oss;
    oss << "[" << mark << "] " << label << " (sepia)";
    return oss.str();
}

std::string SepiaThemeFactory::createTextInput(const std::string& placeholder) const {
    std::ostringstream oss;
    oss << "[SEPIA INPUT: " << placeholder << "]";
    return oss.str();
}

std::string SepiaThemeFactory::createDropdown(const std::string& selected, const std::vector<std::string>& options) const {
    std::ostringstream oss;
    oss << "[SEPIA DROPDOWN: " << selected << "]";
    return oss.str();
}

std::string SepiaThemeFactory::createLabel(const std::string& text) const {
    std::ostringstream oss;
    oss << "[SEPIA LABEL: " << text << "]";
    return oss.str();
}

std::string SepiaThemeFactory::createRadioButton(const std::string& label, bool selected) const {
    std::string mark = selected ? "●" : "○";
    std::ostringstream oss;
    oss << mark << " " << label << " (sepia)";
    return oss.str();
}

std::string SepiaThemeFactory::createSelect(const std::string& label, const std::vector<std::string>& options) const {
    std::ostringstream oss;
    oss << "[SEPIA SELECT: " << label << "]";
    return oss.str();
}

std::string SepiaThemeFactory::createProgressBar(const std::string& label, int percent) const {
    std::ostringstream oss;
    oss << "[SEPIA PROGRESS: " << label << " " << percent << "%]";
    return oss.str();
}