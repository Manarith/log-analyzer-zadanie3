#include <gtest/gtest.h>
#include "Parser.hpp"
#include "Query.hpp"

TEST(ParserTest, ParseLineCorrect) {
    std::string line = "[2023-10-25T10:00:00] [INFO] [AuthService] Test message";
    auto entry = parseLine(line);

    EXPECT_EQ(entry.logLevel, "INFO");
    EXPECT_EQ(entry.source, "AuthService");
    EXPECT_EQ(entry.message, "Test message");
}

TEST(QueryTest, FilterBySource) {
    std::vector<logEntry> logs = {
        {parseTimestamp("2023-10-25T10:00:00"), "INFO", "AuthService", "A"},
        {parseTimestamp("2023-10-25T10:05:00"), "ERROR", "Database", "B"}
    };

    auto result = filterLogs(logs, bySource("AuthService"));

    EXPECT_EQ(result.size(), 1);
    EXPECT_EQ(result[0].source, "AuthService");
}

TEST(QueryTest, FilterByMessage) {
    std::vector<logEntry> logs = {
        {parseTimestamp("2023-10-25T10:00:00"), "INFO", "A", "Transaction OK"},
        {parseTimestamp("2023-10-25T10:05:00"), "INFO", "B", "Other"}
    };

    auto result = filterLogs(logs, byMessageContains("Transaction"));

    EXPECT_EQ(result.size(), 1);
}