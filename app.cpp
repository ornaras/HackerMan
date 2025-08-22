#include "generator.h"
#include "constants.h"
#include "utils.h"

int main() {
	std::string passwd{ genPassword() };
	for (int i{ 0 }; i < MAX_COUNT_TRIES;i++) {
		std::cout << std::endl;
		std::string input{ inputString("Enter a password") };
		if (input == passwd) {
			std::cout << "You win!" << std::endl;
			return 0;
		}
		else {
			std::cout << "Wrong password!" << std::endl;
		}
	}
}