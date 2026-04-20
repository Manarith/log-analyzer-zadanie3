#include "Query.hpp"

LogFilter bySource(const std::string& src) {
    return [src](const LogEntry& e) { return e.source == src; };
}

LogFilter byLevel(const std::string& lvl) {
    return [lvl](const LogEntry& e) { return e.logLevel == lvl; };
}

LogFilter byMessageContains(const std::string& text) {
    return [text](const LogEntry& e) {
        return e.message.find(text) != std::string::npos;
        };
}

LogFilter byTimeRange(std::chrono::system_clock::time_point from,
    std::chrono::system_clock::time_point to) {
    return [from, to](const LogEntry& e) {
        return e.timestamp >= from && e.timestamp <= to;
        };
}

LogFilter andFilter(LogFilter a, LogFilter b) {
    return [a, b](const LogEntry& e) { return a(e) && b(e); };
}

std::vector<LogEntry> filterLogs(const std::vector<LogEntry>& logs, LogFilter filter) {
    std::vector<LogEntry> result;
    for (const auto& log : logs) {
        if (filter(log)) result.push_back(log);
    }
    return result;
}