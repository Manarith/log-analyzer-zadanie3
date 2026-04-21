#include "Query.hpp"

LogFilter bySource(const std::string& src) {
    return [src](const logEntry& e) { return e.source == src; };
}

LogFilter byLevel(const std::string& lvl) {
    return [lvl](const logEntry& e) { return e.logLevel == lvl; };
}

LogFilter byMessageContains(const std::string& text) {
    return [text](const logEntry& e) {
        return e.message.find(text) != std::string::npos;
        };
}

LogFilter byTimeRange(std::chrono::system_clock::time_point from,
    std::chrono::system_clock::time_point to) {
    return [from, to](const logEntry& e) {
        return e.timestamp >= from && e.timestamp <= to;
        };
}

LogFilter andFilter(LogFilter a, LogFilter b) {
    return [a, b](const logEntry& e) { return a(e) && b(e); };
}

std::vector<logEntry> filterLogs(const std::vector<logEntry>& logs, LogFilter filter) {
    std::vector<logEntry> result;
    for (const auto& log : logs) {
        if (filter(log)) result.push_back(log);
    }
    return result;
}