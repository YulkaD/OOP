#include "ThemeRegistry.h"
#include <stdexcept>

ThemeRegistry& ThemeRegistry::getInstance() {
    static ThemeRegistry instance;
    return instance;
}

void ThemeRegistry::registerTheme(const std::string& name, UIComponentFactoryPtr factory) {
    themes[name] = factory;
}

UIComponentFactoryPtr ThemeRegistry::getTheme(const std::string& name) const {
    auto it = themes.find(name);
    if (it != themes.end()) {
        return it->second;
    }
    throw std::runtime_error("Theme not found: " + name);
}

std::vector<std::string> ThemeRegistry::getAvailableThemes() const {
    std::vector<std::string> result;
    for (const auto& pair : themes) {
        result.push_back(pair.first);
    }
    return result;
}