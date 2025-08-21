#include <random>
#include <iostream>

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
		dist(min, max - 1);
	return dist(rng);
}

static std::string genDictionary(int size) {
	std::string dict;
	for (int i{ 0 }; i < size; i++) {
		std::string characters{ SYMBOLS[random(0, std::size(SYMBOLS))] };
		std::string symbol(1, characters[random(0, std::size(characters))]);
		dict.append(symbol);
	}
	std::cout << "Dictionary: " << dict << std::endl;
	return dict;
}

static std::string genPassword(int len, std::string dict) {
	std::string passwd;

	for (int i{ 0 }; i < len; i++) {
		std::string symbol(1, dict[random(0, std::size(dict))]);
		passwd.append(symbol);
	}
	std::cout << "Password: " << passwd << std::endl;
	return passwd;
}
