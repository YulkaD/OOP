#pragma once
#include <string>
#include <vector>
#include <memory>

class UIComponentFactory {
public:
    virtual ~UIComponentFactory() = default;

    virtual std::string createButton(const std::string& label) const = 0;
    virtual std::string createCheckbox(const std::string& label, bool checked) const = 0;
    virtual std::string createTextInput(const std::string& placeholder) const = 0;
    virtual std::string createDropdown(const std::string& selected, const std::vector<std::string>& options) const = 0;
    virtual std::string createLabel(const std::string& text) const = 0;
    virtual std::string createRadioButton(const std::string& label, bool selected) const = 0;
    virtual std::string createSelect(const std::string& label, const std::vector<std::string>& options) const = 0;
    virtual std::string createProgressBar(const std::string& label, int percent) const = 0;
    virtual std::string getThemeName() const = 0;
};

using UIComponentFactoryPtr = std::shared_ptr<UIComponentFactory>;