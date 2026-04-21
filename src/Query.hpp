#ifndef QUERY_HPP
#define QUERY_HPP

#include "LogEntry.hpp"
#include <functional>
#include <vector>

using LogFilter = std::function<bool(const logEntry&)>;

LogFilter bySource(const std::string& src);
LogFilter byLevel(const std::string& lvl);
LogFilter byMessageContains(const std::string& text);
LogFilter byTimeRange(std::chrono::system_clock::time_point from,
    std::chrono::system_clock::time_point to);

LogFilter andFilter(LogFilter a, LogFilter b);

std::vector<logEntry> filterLogs(const std::vector<logEntry>& logs, LogFilter filter);
#endif