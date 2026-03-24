#pragma once
#include <string>
#include <vector>
#include <stdexcept>

class QueryBuilder {
public:
    QueryBuilder() = default;

    QueryBuilder& from(const std::string& table);
    QueryBuilder& select(const std::vector<std::string>& columns);
    QueryBuilder& distinct(); 
    QueryBuilder& where(const std::string& condition);
    QueryBuilder& groupBy(const std::string& column);
    QueryBuilder& having(const std::string& condition);
    QueryBuilder& orderBy(const std::string& column, bool ascending = true);
    QueryBuilder& limit(int limit);
    QueryBuilder& offset(int offset);
    QueryBuilder& innerJoin(const std::string& table, const std::string& condition);
    QueryBuilder& leftJoin(const std::string& table, const std::string& condition);

    std::string build() const;
    void reset();

private:
    std::string m_table;
    std::vector<std::string> m_columns;
    bool m_distinct = false;
    std::string m_where;
    std::string m_groupBy;
    std::string m_having;
    std::string m_orderBy;
    bool m_ascending = true;
    int m_limit = 0;
    int m_offset = 0;
    std::string m_joinTable;
    std::string m_joinCondition;
    bool m_innerJoin = true;

    void validate() const;
};