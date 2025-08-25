#include "generator.h"
#include "utils.h"
#include "constants.h"
#include "locales.h"

Generator::Generator() : dev(), rng(dev()) {
	dict = initDictionary();
	passwd = initPassword();
	passwdLenght = std::size(passwd);
}

int Generator::random(int min, int max) {
	std::uniform_int_distribution<std::mt19937::result_type>
		dist(min, max);
	return dist(rng);
}

std::string Generator::initDictionary() {
	int size{ inputDigit(locales::input_dict_size, (int)DEFAULT_SIZE_DICT) };
	if (size <= 0) size = (int)DEFAULT_SIZE_DICT;
	std::string dict;
	for (int i{ 0 }; i < size; i++) {
		std::string characters{ SYMBOLS[random(0, std::size(SYMBOLS) - 1)] };
		std::string symbol(1, characters[random(0, std::size(characters) - 1)]);
		dict.append(symbol);
	}
#if _DEBUG
	std::cout << locales::dictionary << dict << std::endl;
#endif 
	return dict;
}

std::string Generator::initPassword() {
	int len{ random((int)MIN_SIZE_PASSWORD, (int)MAX_SIZE_PASSWORD) };
	std::string passwd;

	for (int i{ 0 }; i < len; i++) {
		std::string symbol(1, dict[random(0, std::size(dict) - 1)]);
		passwd.append(symbol);
	}
#if _DEBUG
	std::cout << locales::password << passwd << std::endl;
#endif 
	return passwd;
}

bool Generator::check_passwd(std::string input) {
	return passwd == input;
}

void Generator::print_tips(std::string input) {
	int count{ random(0, 1) };
	if (count == 0) return;
	std::cout << std::endl << locales::tips << std::endl;
	if (count >= 1) {
		std::string status;
		unsigned inpSize{ std::size(input) };
		if (inpSize < passwdLenght) status = locales::tip_size_longer;
		else if (inpSize > passwdLenght) status = locales::tip_size_less;
		else status = locales::tip_size_exactly;
		std::cout << "- " << locales::tip_size_begin << status << inpSize << locales::tip_size_end << std::endl;
	}
}