#include <random>
#include "generator.h"
#include "utils.h"
#include "constants.h"

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
	int size{ inputDigit("Input dictionary's size", DEFAULT_SIZE_DICT) };
	std::string dict;
	for (int i{ 0 }; i < size; i++) {
		std::string characters{ SYMBOLS[random(0, std::size(SYMBOLS) - 1)] };
		std::string symbol(1, characters[random(0, std::size(characters) - 1)]);
		dict.append(symbol);
	}
	std::cout << "Dictionary: " << dict << std::endl;
	return dict;
}

std::string genPassword() {
	std::string dict{ genDictionary() };
	int len{ random(MIN_SIZE_PASSWORD, MAX_SIZE_PASSWORD) };
	std::string passwd;

	for (int i{ 0 }; i < len; i++) {
		std::string symbol(1, dict[random(0, std::size(dict) - 1)]);
		passwd.append(symbol);
	}
	std::cout << "Password: " << passwd << std::endl;
	return passwd;
}
