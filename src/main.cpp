#include "parser.hpp"
#include <iostream>
#include <string>

int main() {
	const std::string filename = "data/logs.txt";

	auto logs = loadLogs(filename);


	std::cout << "dziala";
	return 0;
}