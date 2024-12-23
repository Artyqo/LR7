#include <iostream>
#include "head_5.h"

int main() {
    while (true) {
        // Menu
        userMenu();

        bool barrels[240] = {false};
        bool slaves[5] = {false};
        int groups[31];

        std::cout << "Все бочки делятся на 31 группу. Номер группы переводится в двоичную СС и"
                     "\nв зависимости от кол-ва единичных битов вычисляется кол-во бочек в группе. "
                     "\nФормула: 2^(5-i), где i — кол-во единичных битов.\n";


        std::cout << "\nКол-во групп из 32 бочек — 1.\n";
        std::cout << "Кол-во групп из 16 бочек — 5.\n";
        std::cout << "Кол-во групп из 8 бочек — 10.\n";
        std::cout << "Кол-во групп из 4 бочек — 10.\n";
        std::cout << "Кол-во групп из 2 бочек — 5.\n";

        int n;
        std::cout << "\nВведите номер отравленной бочки (1-240): ";
        std::cin >> n;
        n = check(n);

        barrels[n - 1] = true;
        fillgr(groups);
        findgr(groups, slaves, barrels);

        bool new_slaves[] = {false};

        std::cout << "День 1:\n";
        std::cout << "| Первый раб — " << (slaves[0] ? "умер" : "не умер") << "\n";
        std::cout << "| Второй раб — " << (slaves[1] ? "умер" : "не умер") << "\n";
        std::cout << "| Третий раб — " << (slaves[2] ? "умер" : "не умер") << "\n";
        std::cout << "| Четвёртый раб — " << (slaves[3] ? "умер" : "не умер") << "\n";
        std::cout << "| Пятый раб — " << (slaves[4] ? "умер" : "не умер") << "\n";

        const int gr_num = bargr_num(slaves);

        std::cout << "\nСледовательно, группа с отравленной бочкой находится в диапазоне от " << groups[gr_num] + 1 << " — " << groups[gr_num + 1] << "\n";
        std::cout << "И это группа №" << gr_num + 1 << ".\n";

        findbar(gr_num, groups, new_slaves, barrels);


        const int b = bargr_num(new_slaves) + groups[gr_num] + 1;

        for (int i = 0; i < 5; i++) {
            if (slaves[i]) {
                new_slaves[i] = true;
            }
        }

        std::cout << "\nДень 2: \n";
        std::cout << "| Первый раб — " << (new_slaves[0] ? "умер" : "не умер") << "\n";
        std::cout << "| Второй раб — " << (new_slaves[1] ? "умер" : "не умер") << "\n";
        std::cout << "| Третий раб — " << (new_slaves[2] ? "умер" : "не умер") << "\n";
        std::cout << "| Четвёртый раб — " << (new_slaves[3] ? "умер" : "не умер") << "\n";
        std::cout << "| Пятый раб — " << (new_slaves[4] ? "умер" : "не умер") << "\n";

        std::cout << "\nСледовательно, отравленная бочка под номером: " << b << '\n';

        cleanBuf();

        // Restart
        std::string userInput;
        std::cout << "\nПерезапустить программу?(y/n): ";
        std::getline(std::cin, userInput);

        userInput = CheckUserInput(userInput);

        if (userInput.size() == 1 && (userInput[0] == 'n' || userInput[0] == 'N')) {
            break;
        }
    }

    return 0;
}