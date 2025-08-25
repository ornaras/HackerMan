#include "generator.h"
#include "constants.h"
#include "utils.h"
#include "locales.h"

int main() {
	setlocale(LC_ALL, "");
	Generator gen;
	int countAttempts{ inputDigit(locales::input_attempts, (int)DEFAULT_COUNT_ATTEMPTS) };

	for (int i{ 0 }; i < countAttempts; i++) {
		std::cout << std::endl;
		std::string input{ inputString(locales::input_passwd) };
		if (gen.check_passwd(input)) {
			std::cout << locales::you_win << std::endl;
			return 0;
		}
		else {
			std::cout << locales::wrong_passwd << std::endl;
			gen.print_tips(input);
		}
	}
	std::cout << locales::you_lose << std::endl;
}