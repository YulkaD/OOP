#pragma once
#include "ComponentFactory.h"
#include <string>
#include <vector>

class UIRenderer {
public:
    static void renderLoginForm(const UIComponentFactory& factory);
    static void renderSettingsPanel(const UIComponentFactory& factory);
    static void renderAdvancedSettings(const UIComponentFactory& factory);
    static void renderDashboard(const UIComponentFactory& factory);
};