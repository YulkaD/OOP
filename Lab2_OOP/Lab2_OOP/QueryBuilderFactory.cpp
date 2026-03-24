#include "QueryBuilderFactory.h"

std::unique_ptr<QueryBuilder> QueryBuilderFactory::createSelectBuilder() {
    return std::make_unique<QueryBuilder>();
}

std::unique_ptr<QueryBuilder> QueryBuilderFactory::createInsertBuilder(const std::string& table, const std::vector<std::string>& columns) {
    return std::make_unique<QueryBuilder>();
}

std::unique_ptr<QueryBuilder> QueryBuilderFactory::createUpdateBuilder(const std::string& table) {
    return std::make_unique<QueryBuilder>();
}

std::unique_ptr<QueryBuilder> QueryBuilderFactory::createDeleteBuilder(const std::string& table) {
    return std::make_unique<QueryBuilder>();
}