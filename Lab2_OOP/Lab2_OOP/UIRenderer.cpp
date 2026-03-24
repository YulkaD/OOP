#include "UIRenderer.h"
#include <iostream>

void UIRenderer::renderLoginForm(const UIComponentFactory& factory) {
    std::cout << "\n--- Login Form (" << factory.getThemeName() << ") ---\n";
    std::cout << factory.createLabel("User Credentials") << "\n";
    std::cout << factory.createTextInput("Email address") << "\n";
    std::cout << factory.createTextInput("Password") << "\n";
    std::cout << factory.createCheckbox("Remember me", false) << "\n";
    std::cout << factory.createButton("Sign In") << "\n";
    std::cout << factory.createButton("Sign Up") << "\n";
    std::cout << "---\n";
}

void UIRenderer::renderSettingsPanel(const UIComponentFactory& factory) {
    std::cout << "\n--- Settings (" << factory.getThemeName() << ") ---\n";
    std::cout << factory.createLabel("Application Settings") << "\n";
    std::vector<std::string> langs = { "English", "Ukrainian", "German" };
    std::cout << factory.createDropdown("English", langs) << "\n";
    std::cout << factory.createCheckbox("Enable notifications", true) << "\n";
    std::cout << factory.createRadioButton("Public profile", true) << "\n";
    std::cout << factory.createButton("Save Settings") << "\n";
    std::cout << "---\n";
}

void UIRenderer::renderAdvancedSettings(const UIComponentFactory& factory) {
    std::cout << "\n--- Advanced Settings (" << factory.getThemeName() << ") ---\n";
    std::cout << factory.createLabel("Cache Settings") << "\n";
    std::vector<std::string> backends = { "Redis", "Memcached", "File" };
    std::cout << factory.createSelect("Cache Backend", backends) << "\n";
    std::cout << factory.createCheckbox("Enable compression", true) << "\n";
    std::cout << factory.createButton("Apply") << "\n";
    std::cout << "---\n";
}

void UIRenderer::renderDashboard(const UIComponentFactory& factory) {
    std::cout << "\n--- Dashboard (" << factory.getThemeName() << ") ---\n";
    std::cout << factory.createProgressBar("CPU Usage", 45) << "\n";
    std::cout << factory.createProgressBar("Memory", 72) << "\n";
    std::cout << factory.createProgressBar("Disk", 33) << "\n";
    std::cout << factory.createButton("Refresh") << "\n";
    std::cout << "---\n";
}