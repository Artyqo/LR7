#include <iostream>
#include "head_2.h"

void userMenu() {
	std::cout << "\nЧисла, введённые пользователем суммируются в обратном коде. Программа выводит результат в прямом коде.\n";
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

std::string reverseCode(const std::string& str) {
	std::string direct = "";
	std::string num = str;

	while (num != "0") { // O(log(num)) - количество итераций пропорционально числу цифр в num (в двоичной системе).
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

	if (str[0] == '-') {
		for (int i = 1; i < direct.size(); i++) { // O(L)
			if (direct[i] == '1') direct[i] = '0';
			else if (direct[i] == '0') direct[i] = '1';
		}
	}

	return direct;
}

std::string addReverseCode(const std::string& num1, const std::string& num2) {
	int carry = 0;
	std::string result = "";

	std::string a = num1, b = num2;

	if (a.size() < b.size()) { // O(L)
		if (num1[0] == '1') {
			a.insert(1, b.size() - a.size() + 1, '1'); // O(L)
		}
		else if (num1[0] == '0') {
			a.insert(0, b.size() - a.size() + 1, '0'); // O(L)
		}

		if (b[0] == '1') b.insert(1, 1, '1'); // O(L)
		else if (b[0] == '0') b.insert(0, 1, '0'); // O(L)
	}
	else if (b.size() < a.size()) { // O(L)
		if (num2[0] == '1')
			b.insert(1, a.size() - b.size() + 1, '1'); // O(L)
		else if (num2[0] == '0') {
			b.insert(0, a.size() - b.size() + 1, '0'); // O(L)
		}
		if (a[0] == '1') a.insert(1, 1, '1'); // O(L)
		else if (a[0] == '0') a.insert(0, 1, '0'); // O(L)
	}
	else if (a.size() == b.size()) { // O(L)
		if (a[0] == '1') a.insert(1, 1, '1'); // O(L)
		else if (a[0] == '0') a.insert(0, 1, '0'); // O(L)

		if (b[0] == '1') b.insert(1, 1, '1'); // O(L)
		else if (b[0] == '0') b.insert(0, 1, '0'); // O(L)
	}

	for (int i = a.size() - 1; i >= 0; i--) { // O(L)
		int bitA = a[i] - '0';
		int bitB = b[i] - '0';
		int sum = bitA + bitB + carry;

		result += (sum % 2) + '0';
		carry = sum / 2;
	}

	std::reverse(result.begin(), result.end()); // O(L)

	if (carry == 0 && result[0] == '1') {
		for (int i = 1; i < result.size(); i++) { // O(L)
			if (result[i] == '1') result[i] = '0';
			else if (result[i] == '0') result[i] = '1';
		}
	}

	std::string carry1 = "";
	std::string pere = "";

	if (carry == 1) {
		int carry_n = 0;
		pere.insert(0, result.size() - 1, '0'); // O(L)
		pere += "1";

		for (int i = result.size() - 1; i >= 0; i--) { // O(L)
			int bitA = result[i] - '0';
			int bitB = pere[i] - '0';
			int sum = bitA + bitB + carry_n;

			carry1 += (sum % 2) + '0';
			carry_n = sum / 2;
		}

		std::reverse(carry1.begin(), carry1.end()); // O(L)

		for (int i = 1; i < carry1.size(); i++) { // O(L)
			if (carry1[i] == '1') carry1[i] = '0';
			else if (carry1[i] == '0') carry1[i] = '1';
		}

		result = carry1;
	}

	return result;
}



std::string CheckUserInput(std::string userInput) {
	while (!(userInput.size() == 1 && (userInput[0] == 'n' || userInput[0] == 'N' || userInput[0] == 'y' || userInput[0] == 'Y'))) {
		std::cout << "Неправильный ввод, попробуйте снова: ";
		std::getline(std::cin, userInput);
	}
	return userInput;
}
