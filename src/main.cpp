#include "Parser.hpp"
#include "Query.hpp"
#include <iostream>

int main() {
    auto logs = loadLogs("logs.txt");

    auto query = bySource("AuthService");
    auto results = filterLogs(logs, query);

    for (const auto& log : results) {
        std::cout << log.source << " - " << log.message << std::endl;
    }

    return 0;
}