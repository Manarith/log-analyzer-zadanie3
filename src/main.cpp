#include "Parser.hpp"
#include "Query.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

//Wypisanie wyniku
std::string formatTimestamp(const std::chrono::system_clock::time_point& tp) {
    std::time_t t = std::chrono::system_clock::to_time_t(tp);
    std::tm tm{};
    localtime_s(&tm, &t);

    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%dT%H:%M:%S");
    return oss.str();
}

void printLog(const logEntry& log) {
    std::cout
        << "[" << formatTimestamp(log.timestamp) << "] "
        << "[" << log.logLevel << "] "
        << "[" << log.source << "] "
        << log.message << "\n";
}
//

int main() {
    std::string filename = "logs.txt";
    std::cout << "Loading logs from: " << filename << "\n";

    auto logs = loadLogs(filename);
    std::cout << "Loaded logs: " << logs.size() << "\n\n";

    //przykładowe zapytania
    std::cout << "Filtering: source = AuthService\n\n";

    auto query = bySource("AuthService");
    auto results = filterLogs(logs, query);

    std::cout << "Found: " << results.size() << " matching logs\n\n";

    for (const auto& log : results) {
        printLog(log);
    }

    if (results.empty()) {
        std::cout << "No results found.\n";
    }

    std::cout << "Filtering: message = 'Transaction'\n\n";
    query = byMessageContains("Transaction");
    results = filterLogs(logs, query);

    std::cout << "Found: " << results.size() << " matching logs\n\n";

    for (const auto& log : results) {
        printLog(log);
    }

    if (results.empty()) {
        std::cout << "No results found.\n";
    }
    return 0;
}