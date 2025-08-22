#include "utils.h"
#include <sstream>

int inputDigit(std::string text, int defaultValue) {
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

std::string inputString(std::string text) {
	std::cout << text << ": ";
	std::string value{ "" };
	std::getline(std::cin, value);
	return value;
}