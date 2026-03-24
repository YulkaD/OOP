#pragma once
#include "ComponentFactory.h"

class SepiaThemeFactory : public UIComponentFactory {
public:
    std::string createButton(const std::string& label) const override;
    std::string createCheckbox(const std::string& label, bool checked) const override;
    std::string createTextInput(const std::string& placeholder) const override;
    std::string createDropdown(const std::string& selected, const std::vector<std::string>& options) const override;
    std::string createLabel(const std::string& text) const override;
    std::string createRadioButton(const std::string& label, bool selected) const override;
    std::string createSelect(const std::string& label, const std::vector<std::string>& options) const override;
    std::string createProgressBar(const std::string& label, int percent) const override;
    std::string getThemeName() const override { return "sepia"; }
};