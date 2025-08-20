#include <random>
#include <iostream>

const char symbols[]{ "qwertyuiopasdfghjklzxcvbm1234567890QWERTYUIOPASDFGHJKLZXCVBNM" };

int random(int min, int max) {
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type>
		dist(min, max);
	return dist(rng);
}

std::string genPassword(int len) {
	std::string passwd{ "" };

	for (int i{ 0 }; i < len; i++)
	{
		std::string symbol(1, symbols[random(0, std::size(symbols))]);
		passwd.append(symbol);
	}
	return passwd;
}

int main()
{
	int lenPasswd{ random(7, 15) };

	std::string passwd;
	passwd = genPassword(lenPasswd);
	std::cout << passwd;
}