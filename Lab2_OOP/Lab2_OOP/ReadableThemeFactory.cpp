#include "ReadableThemeFactory.h"
#include <sstream>

std::string ReadableThemeFactory::createButton(const std::string& label) const {
    std::ostringstream oss;
    oss << "[READABLE BTN: " << label << " | large font]";
    return oss.str();
}

std::string ReadableThemeFactory::createCheckbox(const std::string& label, bool checked) const {
    std::string mark = checked ? "[YES]" : "[NO]";
    std::ostringstream oss;
    oss << mark << " " << label << " (readable)";
    return oss.str();
}

std::string ReadableThemeFactory::createTextInput(const std::string& placeholder) const {
    std::ostringstream oss;
    oss << "[READABLE INPUT: " << placeholder << "]";
    return oss.str();
}

std::string ReadableThemeFactory::createDropdown(const std::string& selected, const std::vector<std::string>& options) const {
    std::ostringstream oss;
    oss << "[READABLE DROPDOWN: " << selected << "]";
    return oss.str();
}

std::string ReadableThemeFactory::createLabel(const std::string& text) const {
    std::ostringstream oss;
    oss << "[READABLE LABEL: " << text << "]";
    return oss.str();
}

std::string ReadableThemeFactory::createRadioButton(const std::string& label, bool selected) const {
    std::string mark = selected ? "[*]" : "[ ]";
    std::ostringstream oss;
    oss << mark << " " << label << " (readable)";
    return oss.str();
}

std::string ReadableThemeFactory::createSelect(const std::string& label, const std::vector<std::string>& options) const {
    std::ostringstream oss;
    oss << "[READABLE SELECT: " << label << "]";
    return oss.str();
}

std::string ReadableThemeFactory::createProgressBar(const std::string& label, int percent) const {
    std::ostringstream oss;
    oss << "[READABLE PROGRESS: " << label << " " << percent << "%]";
    return oss.str();
}