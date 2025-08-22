#pragma once
#include <iostream>
#include <random>

class Generator{
	std::random_device dev;
	std::mt19937 rng;
	std::string dict;
	std::string passwd;
	int passwdLenght;

public:
	Generator();

	void print_tips(std::string);
	bool check_passwd(std::string);
private:
	std::string initDictionary();
	std::string initPassword();
	int random(int, int);
};
