#pragma once
#include "QueryBuilder.h"
#include <memory>

enum class QueryType {
    SELECT,
    INSERT,
    UPDATE,
    DELETE
};

class QueryBuilderFactory {
public:
    static std::unique_ptr<QueryBuilder> createSelectBuilder();
    static std::unique_ptr<QueryBuilder> createInsertBuilder(const std::string& table, const std::vector<std::string>& columns);
    static std::unique_ptr<QueryBuilder> createUpdateBuilder(const std::string& table);
    static std::unique_ptr<QueryBuilder> createDeleteBuilder(const std::string& table);
};