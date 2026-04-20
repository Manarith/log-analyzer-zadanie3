#include "Parser.hpp"
#include <regex>
#include <fstream>
#include <sstream>
#include <iomanip>

std::chrono::system_clock::time_point parseTimestamp(const std::string& timestamp) {
	std::tm tm = {};
	std::istringstream ss(timestamp);
	ss >> std::get_time(&tm, "%Y-%m-%dT%H:%M:%S");
	return std::chrono::system_clock::from_time_t(std::mktime(&tm));
}

logEntry parseLine(const std::string& line) {
	std::regex pattern(R"(\[(.*?)\] \[(.*?)\] \[(.*?)\] (.*))"); //[TIMESTAMP] [LOG_LEVEL] [SOURCE] Message
	std::smatch match;

	if (!std::regex_match(line, match, pattern)) {
		throw std::runtime_error("Invalid log format");
	}
	logEntry entry;
	entry.timestamp = parseTimestamp(match[1]);
	entry.logLevel = match[2];
	entry.source = match[3];
	entry.message = match[4];

	return entry;
}

std::vector<logEntry> loadLogs(const std::string& filename) {
	std::ifstream file(filename);
	if (!file) {
		throw std::runtime_error("Cannot open file");
	}
	std::vector<logEntry> logs;
	std::string line;

	while (std::getline(file, line)) {
		logs.push_back(parseLine(line));
	}

	return logs;
}
