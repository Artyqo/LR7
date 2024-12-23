#include <iostream>
#include "head_2.h"

int main() {
    while (true) {
        // Menu
        userMenu();

        std::string number1;
        std::string number2;

        std::cout << "Введите 1-ое число: ";
        std::getline(std::cin, number1);

        number1 = Check(number1);

        std::cout << "Введите 2-ое число: ";
        std::getline(std::cin, number2);

        number2 = Check(number2);

        std::string code1 = reverseCode(number1);
        std::string code2 = reverseCode(number2);

        std::string sum = addReverseCode(code1, code2);

        std::cout << "Ваши числа в обратном коде: " << code1 << " " << code2 << std::endl;

        std::cout << "Сумма чисел в прямом коде: " << sum << std::endl;

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