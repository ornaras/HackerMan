#include <iostream>
#include <sstream>

static int inputDigit(std::string text, int defaultValue) {
	std::cout << text << " [" << defaultValue << "]: ";
	std::string raw{ "" };
	std::getline(std::cin, raw);
	try {
		return std::stoi(raw);
	}
	catch (const std::invalid_argument& e) {
		return defaultValue;
	}
	catch (const std::out_of_range& e) {
		return defaultValue;
	}
}