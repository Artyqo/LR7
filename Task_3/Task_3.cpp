#include <iostream>

#include "head_3.h"

int main() {

    while (true) {
        // Menu
        userMenu();

        long double base = check("Введите основание системы счисления: ");
        if (base <= 0) {
            break;
        }
        long long size;
        std::string* alphabet = genalpha(base, size);
        std::string num1, num2;
        num1 = checkkk("Введите первое число: ");
        num2 = checkkk("Введите второе число: ");
        char a;
        std::cout << "Введите операцию (+ или -): ";
        std::cin >> a;

        if (a == '+') {
            std::string result = an(num1, num2, alphabet, size);
            if (result.empty()) {
                std::cout << "Ошибка при выполнении сложения.\n";
            } else {
                std::cout << "Результат: " << result << "\n";
            }
        } else if (a == '-') {
            std::string result = sn(num1, num2, alphabet, size);
            if (result.empty()) {
                std::cout << "Ошибка при выполнении вычитания.\n";
            } else {
                std::cout << "Результат: " << result << "\n";
            }
        } else {
            std::cout << "Неподдерживаемая операция.\n";
        }
        delete[] alphabet;

        cleanBuf();

        // Restart
        std::string userInput;
        std::cout << "\nRestart the programme?(y/n): ";
        std::getline(std::cin, userInput);

        userInput = CheckUserInput(userInput);

        if (userInput.size() == 1 && (userInput[0] == 'n' || userInput[0] == 'N')) {
            break;
        }
    }

    return 0;
}