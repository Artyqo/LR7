#include <iostream>
#include "head_1.h"
void userMenu() {
	std::cout << "\nЧисла, введённые пользователем переводятся из естественной формы в прямой код.\n";
	std::cout << "Задание №1(вар.4) выполнил Борисов Артём, гр. 453502\n";
	std::cout << "————————————————————————————————————————————————————\n";
}

void cleanBuf() {
	std::cin.clear();
	std::cin.ignore(1000000, '\n');
}

bool Valid(const std::string &str) {
	long long len = str.size();

	for (int i = 0; i < len; i++) { // O(len)
		if (str[i] == '-' && str[i+1] != '\0') continue;
		if (!isdigit(str[i]) || str[i] == ' ') {
			return false;
		}
	}

	return true;
}

std::string Check(std::string num) {
	while (!Valid(num)) {
		std::cout << "Вводите только цифры!\nПопробуйте снова: ";
		std::getline(std::cin, num);
	}
	return num;
}

std::string directCode(std::string str) {
	std::string direct = "";
	std::string num = str;

	while (num != "0") { // O(log(num))
		int remainder = 0;
		std::string newNum = "";

		for (char c : num) { // O(L) - L — длина строки num.
			if (c == '-') continue;
			int current = remainder * 10 + (c - '0');
			newNum += (current / 2) + '0';
			remainder = current % 2;
		}

		newNum.erase(0, std::min(newNum.find_first_not_of('0'), newNum.size() - 1)); // O(L)

		direct += std::to_string(remainder);
		num = newNum;
	}

	std::reverse(direct.begin(), direct.end()); // O(L)

	return direct;
}

std::string CheckUserInput(std::string userInput) {
	while (!(userInput.size() == 1 && (userInput[0] == 'n' || userInput[0] == 'N' || userInput[0] == 'y' || userInput[0] == 'Y'))) {
		std::cout << "Неправильный ввод, попробуйте снова: ";
		std::getline(std::cin, userInput);
	}
	return userInput;
}