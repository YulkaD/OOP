#include "QueryBuilder.h"
#include <sstream>

QueryBuilder& QueryBuilder::from(const std::string& table) {
    m_table = table;
    return *this;
}

QueryBuilder& QueryBuilder::select(const std::vector<std::string>& columns) {
    m_columns = columns;
    return *this;
}

QueryBuilder& QueryBuilder::distinct() {
    m_distinct = true;
    return *this;
}

QueryBuilder& QueryBuilder::where(const std::string& condition) {
    m_where = condition;
    return *this;
}

QueryBuilder& QueryBuilder::groupBy(const std::string& column) {
    m_groupBy = column;
    return *this;
}

QueryBuilder& QueryBuilder::having(const std::string& condition) {
    m_having = condition;
    return *this;
}

QueryBuilder& QueryBuilder::orderBy(const std::string& column, bool ascending) {
    m_orderBy = column;
    m_ascending = ascending;
    return *this;
}

QueryBuilder& QueryBuilder::limit(int limit) {
    m_limit = limit;
    return *this;
}

QueryBuilder& QueryBuilder::offset(int offset) {
    m_offset = offset;
    return *this;
}

QueryBuilder& QueryBuilder::innerJoin(const std::string& table, const std::string& condition) {
    m_joinTable = table;
    m_joinCondition = condition;
    m_innerJoin = true;
    return *this;
}

QueryBuilder& QueryBuilder::leftJoin(const std::string& table, const std::string& condition) {
    m_joinTable = table;
    m_joinCondition = condition;
    m_innerJoin = false;
    return *this;
}

void QueryBuilder::validate() const {
    if (m_table.empty()) {
        throw std::runtime_error("Table name cannot be empty");
    }
    if (m_offset > 0 && m_limit == 0) {
        throw std::runtime_error("OFFSET cannot be used without LIMIT");
    }
    if (!m_having.empty() && m_groupBy.empty()) {
        throw std::runtime_error("HAVING clause cannot be used without GROUP BY");
    }
}

std::string QueryBuilder::build() const {
    validate();

    std::ostringstream sql;

    sql << "SELECT ";
    if (m_distinct) sql << "DISTINCT ";

    if (m_columns.empty()) {
        sql << "*";
    }
    else {
        for (size_t i = 0; i < m_columns.size(); ++i) {
            if (i > 0) sql << ", ";
            sql << m_columns[i];
        }
    }

    sql << " FROM " << m_table;

    if (!m_joinTable.empty() && !m_joinCondition.empty()) {
        sql << (m_innerJoin ? " INNER JOIN " : " LEFT JOIN ")
            << m_joinTable << " ON " << m_joinCondition;
    }

    if (!m_where.empty()) {
        sql << " WHERE " << m_where;
    }

    if (!m_groupBy.empty()) {
        sql << " GROUP BY " << m_groupBy;
        if (!m_having.empty()) {
            sql << " HAVING " << m_having;
        }
    }

    if (!m_orderBy.empty()) {
        sql << " ORDER BY " << m_orderBy;
        sql << (m_ascending ? " ASC" : " DESC");
    }

    if (m_limit > 0) {
        sql << " LIMIT " << m_limit;
        if (m_offset > 0) sql << " OFFSET " << m_offset;
    }

    return sql.str();
}

void QueryBuilder::reset() {
    m_table.clear();
    m_columns.clear();
    m_distinct = false;
    m_where.clear();
    m_groupBy.clear();
    m_having.clear();
    m_orderBy.clear();
    m_ascending = true;
    m_limit = 0;
    m_offset = 0;
    m_joinTable.clear();
    m_joinCondition.clear();
    m_innerJoin = true;
}