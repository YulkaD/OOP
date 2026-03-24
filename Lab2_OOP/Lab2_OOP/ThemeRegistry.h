#pragma once
#include "ComponentFactory.h"
#include <map>
#include <string>
#include <vector>
#include <memory>

class ThemeRegistry {
public:
    static ThemeRegistry& getInstance();

    void registerTheme(const std::string& name, UIComponentFactoryPtr factory);
    UIComponentFactoryPtr getTheme(const std::string& name) const;
    std::vector<std::string> getAvailableThemes() const;

private:
    ThemeRegistry() = default;
    ~ThemeRegistry() = default;
    ThemeRegistry(const ThemeRegistry&) = delete;
    ThemeRegistry& operator=(const ThemeRegistry&) = delete;

    std::map<std::string, UIComponentFactoryPtr> themes;
};