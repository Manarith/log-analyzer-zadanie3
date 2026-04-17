#ifndef LOG_ENTRY_HPP
#define LOG_ENTRY_HPP
#include <string>
#include <chrono>

struct logEntry {
	std::chrono::system_clock::time_point timestamp;
	std::string logLevel;
	std::string source;
	std::string Message;
};
#endif