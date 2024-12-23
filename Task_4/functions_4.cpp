#include <iostream>
#include "head_4.h"

void userMenu() {
	std::cout << "\nПрограмма проверяет, делится ли введённое пользователем число на 3 простых.\n";
	std::cout << "Задание №4 выполнил Борисов Артём, гр. 453502\n";
	std::cout << "—————————————————————————————————————————————\n";
}

void cleanBuf() {
	std::cin.clear();
	std::cin.ignore(1000000, '\n');
}

bool isDivisible(int n, int p) { // O((n/p) * logn)
	int r = n;
	while (r >= p) { // O(n/p)
		int s = p;
		while ((s << 1) <= r) s <<= 1; // O(logn)
		r -= s;
	}
	return r == 0;
}

long double check(long double n) {
	while (std::cin.fail() || std::cin.peek() != '\n') {
		std::cin.clear();
		std::cin.ignore(10000000, '\n');
		std::cout << "Неправильный ввод, попробуйте снова: ";
		std::cin >> n;
	}

	return n;
}

std::string CheckUserInput(std::string userInput) {
	while (!(userInput.size() == 1 && (userInput[0] == 'n' || userInput[0] == 'N' || userInput[0] == 'y' || userInput[0] == 'Y'))) {
		std::cout << "Неправильный ввод, попробуйте снова: ";
		std::getline(std::cin, userInput);
	}
	return userInput;
}