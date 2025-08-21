#include "generator.cpp"
#include "utils.cpp"

int main() {
	int sizeDict{ inputDigit("Input dictionary's size", 75)};
	int lenPasswd{ random(7, 16) };

	std::string dict{ genDictionary(sizeDict) };
	std::string passwd{ genPassword(lenPasswd, dict) };
}