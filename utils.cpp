#include <iostream>

static int inputDigit(std::string text, int defaultValue) {

	std::cout << text << " [" << defaultValue << "]: ";
	int value;
	if (std::cin.peek() == '\n' || !(std::cin >> value)) {
		return defaultValue;
	}
	return value;
}