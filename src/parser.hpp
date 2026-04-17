#ifndef PARSER_HPP
#define PARSER_HPP
#include "LogEntry.hpp"
#include <vector>
#include <string>

logEntry parseLine(const std::string& line);
std::vector<logEntry> loadLogs(const std::string& filename);
std::chrono::system_clock::time_point parseTimestamp(const std::string& timestamp);

#endif