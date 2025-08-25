#pragma once
#include <iostream>

namespace locales {
#if _RUSSIAN
	const std::string you_win = "Ты победил!";
	const std::string wrong_passwd = "Неверный пароль!";
	const std::string input_passwd = "Введите пароль";
	const std::string input_attempts = "Введите количество попыток";
	const std::string input_dict_size = "Введите размер словаря";
	const std::string dictionary = "Словарь: ";
	const std::string password = "Пароль: ";
	const std::string tips = "Подсказки:";

	const std::string tip_size_longer = "более ";
	const std::string tip_size_less = "менее ";
	const std::string tip_size_exactly = "";
	const std::string tip_size_begin = "Пароль состоит из ";
	const std::string tip_size_end = " символов";
#else
	const std::string you_win = "You Win!";
	const std::string wrong_passwd = "Wrong password!";
	const std::string input_passwd = "Enter a password";
	const std::string input_attempts = "Input number of attempts";
	const std::string input_dict_size = "Input dictionary's size";
	const std::string dictionary = "Dictionary: ";
	const std::string password = "Password: ";
	const std::string tips = "Tips:";

	const std::string tip_size_longer = "longer than ";
	const std::string tip_size_less = "less than ";
	const std::string tip_size_exactly = "exactly ";
	const std::string tip_size_begin = "The password is ";
	const std::string tip_size_end = " characters";
#endif
}