#include "generator.h"
#include "constants.h"
#include "utils.h"

int main() {
	Generator gen;
	int countAttempts{ inputDigit("Input number of attempts", (int)DEFAULT_COUNT_ATTEMPTS) };

	for (int i{ 0 }; i < countAttempts; i++) {
		std::cout << std::endl;
		std::string input{ inputString("Enter a password") };
		if (gen.check_passwd(input)) {
			std::cout << "You win!" << std::endl;
			return 0;
		}
		else {
			std::cout << "Wrong password!" << std::endl;
			//todo tips
		}
	}
}