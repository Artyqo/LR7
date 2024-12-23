#include <iostream>
#include "head_1.h"

int main() {
    while (true) {
        // Menu
        userMenu();

        std::string number;

        std::cout << "Введите число: ";
        std::getline(std::cin, number);

        number = Check(number);
        std::string code = directCode(number);

        std::cout << "Ваше число в обратном коде: " << code << std::endl;

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
