#include <random>
#include <iostream>
#include "utils.cpp"

const std::string SYMBOLS[]{
	"qwertyuiopasdfghjklzxcvbm",
	"QWERTYUIOPASDFGHJKLZXCVBNM",
	"1234567890",
	"[]{}()<>"
};

static int random(int min, int max) {
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type>
		dist(min, max);
	return dist(rng);
}

static std::string genDictionary() {
	int size{ inputDigit("Input dictionary's size", 75) };
	std::string dict;
	for (int i{ 0 }; i < size; i++) {
		std::string characters{ SYMBOLS[random(0, std::size(SYMBOLS) - 1)] };
		std::string symbol(1, characters[random(0, std::size(characters) - 1)]);
		dict.append(symbol);
	}
	std::cout << "Dictionary: " << dict << std::endl;
	return dict;
}

static std::string genPassword() {
	std::string dict{ genDictionary() };
	int len{ random(7, 15) };
	std::string passwd;

	for (int i{ 0 }; i < len; i++) {
		std::string symbol(1, dict[random(0, std::size(dict) - 1)]);
		passwd.append(symbol);
	}
	std::cout << "Password: " << passwd << std::endl;
	return passwd;
}
