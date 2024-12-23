#include <iostream>
#include "head_4.h"

int main() {
    while (true) {
        // Menu
        userMenu();

        std::cout << "Введите число: ";
        long double num;
        std::cin >> num;
        num = check(num);
        const int prost1 = 3;
        const int prost2 = 61;
        const int prost3 = 131;
        num = (num < 0) ? -num : num;
        std::cout << "На " << prost1 << ": " << (isDivisible(num, prost1) ? "Да" : "Нет") << '\n';
        std::cout << "На " << prost2 << ": " << (isDivisible(num, prost2) ? "Да" : "Нет") << '\n';
        std::cout << "На " << prost3 << ": " << (isDivisible(num, prost3) ? "Да" : "Нет") << '\n';

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