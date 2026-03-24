#include "ComponentFactory.h"
#include "LightThemeFactory.h"
#include "DarkThemeFactory.h"
#include "HighContrastThemeFactory.h"
#include "SepiaThemeFactory.h"
#include "NordThemeFactory.h"
#include "CompactThemeFactory.h"
#include "ReadableThemeFactory.h"
#include "ThemeRegistry.h"
#include "UIRenderer.h"
#include "QueryBuilder.h"
#include "QueryBuilderFactory.h"
#include <iostream>
#include <memory>
#include <vector>
#include <stdexcept>

void demonstrateThemes() {
    std::cout << "\n========================================\n";
    std::cout << "UI THEMES DEMONSTRATION\n";
    std::cout << "========================================\n";

    auto& registry = ThemeRegistry::getInstance();
    registry.registerTheme("light", std::make_shared<LightThemeFactory>());
    registry.registerTheme("dark", std::make_shared<DarkThemeFactory>());
    registry.registerTheme("highcontrast", std::make_shared<HighContrastThemeFactory>());
    registry.registerTheme("sepia", std::make_shared<SepiaThemeFactory>());
    registry.registerTheme("nord", std::make_shared<NordThemeFactory>());
    registry.registerTheme("compact", std::make_shared<CompactThemeFactory>());
    registry.registerTheme("readable", std::make_shared<ReadableThemeFactory>());

    auto themes = registry.getAvailableThemes();
    std::cout << "Available themes (" << themes.size() << "): ";
    for (const auto& theme : themes) {
        std::cout << theme << " ";
    }
    std::cout << "\n\n";

    for (const auto& themeName : themes) {
        auto factory = registry.getTheme(themeName);
        UIRenderer::renderLoginForm(*factory);
    }

    std::cout << "\n--- NEW COMPONENT DEMO (Progress Bar) ---\n";
    auto darkFactory = registry.getTheme("dark");
    UIRenderer::renderDashboard(*darkFactory);
}

void demonstrateQueryBuilder() {
    std::cout << "\n========================================\n";
    std::cout << "QUERY BUILDER DEMONSTRATION\n";
    std::cout << "========================================\n";

    try {
        QueryBuilder qb1;
        std::string q1 = qb1.from("users")
            .select(std::vector<std::string>{"id", "name", "email"})
            .where("active = 1")
            .build();
        std::cout << "Q1: " << q1 << "\n\n";

        QueryBuilder qb2;
        std::string q2 = qb2.from("orders")
            .select(std::vector<std::string>{"customer_id", "COUNT(*) as order_count"})
            .distinct()
            .where("total > 100")
            .groupBy("customer_id")
            .having("COUNT(*) > 5")
            .orderBy("order_count", false)
            .limit(10)
            .build();
        std::cout << "Q2: " << q2 << "\n\n";

        QueryBuilder qb3;
        std::string q3 = qb3.from("users u")
            .select(std::vector<std::string>{"u.name", "o.total"})
            .innerJoin("orders o", "u.id = o.user_id")
            .where("o.total > 500")
            .limit(5)
            .build();
        std::cout << "Q3: " << q3 << "\n\n";

    }
    catch (const std::runtime_error& e) {
        std::cout << "Error: " << e.what() << "\n";
    }
}

void demonstrateValidation() {
    std::cout << "\n========================================\n";
    std::cout << "VALIDATION DEMONSTRATION\n";
    std::cout << "========================================\n";

    try {
        std::cout << "Test 1: HAVING without GROUP BY\n";
        QueryBuilder qb1;
        qb1.from("users").select(std::vector<std::string>{"*"}).having("COUNT(*) > 5").build();
    }
    catch (const std::runtime_error& e) {
        std::cout << "[OK] Caught: " << e.what() << "\n\n";
    }

    try {
        std::cout << "Test 2: OFFSET without LIMIT\n";
        QueryBuilder qb2;
        qb2.from("users").select(std::vector<std::string>{"*"}).offset(10).build();
    }
    catch (const std::runtime_error& e) {
        std::cout << "[OK] Caught: " << e.what() << "\n\n";
    }

    try {
        std::cout << "Test 3: No table specified\n";
        QueryBuilder qb3;
        qb3.select(std::vector<std::string>{"*"}).build();
    }
    catch (const std::runtime_error& e) {
        std::cout << "[OK] Caught: " << e.what() << "\n\n";
    }
}

void demonstrateFactory() {
    std::cout << "\n========================================\n";
    std::cout << "FACTORY DEMONSTRATION\n";
    std::cout << "========================================\n";

    auto builder = QueryBuilderFactory::createSelectBuilder();
    std::string query = builder->from("users")
        .select(std::vector<std::string>{"id", "name"})
        .where("age > 18")
        .build();
    std::cout << "Factory query: " << query << "\n\n";
}

int main() {
    std::cout << "========================================\n";
    std::cout << "LAB 02 - Design Patterns\n";
    std::cout << "Variant 10: Compact & Readable themes\n";
    std::cout << "========================================\n";

    demonstrateThemes();
    demonstrateQueryBuilder();
    demonstrateValidation();
    demonstrateFactory();

    std::cout << "\nProgram completed!\n";
    return 0;
}