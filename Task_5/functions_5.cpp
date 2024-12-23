#include <iostream>
#include "head_5.h"

void userMenu() {
	std::cout << "\nПатриций решил устроить праздник и для этого приготовил 240 бочек вина. Однако к нему пробрался "
              "\nнедоброжелатель по имени Пользователь, который подсыпал яд в одну из бочек. Недоброжелателя тут же "
              "\nпоймали, дальнейшая его судьба неизвестна, но ходят слухи, что он проверяет консольный ввод в аду в "
              "\nкачестве наказания, однако сейчас не об этом. Про яд известно, что человек, который его выпил, умирает в "
              "\nтечение 24 часов. До праздника осталось два дня, то есть 48 часов. У патриция есть пять рабов, которыми "
              "\nон готов пожертвовать, чтобы узнать, в какой именно бочке яд. Вы близкий друг Патриция и совершенно не "
              "\nхотите стать одним из тех рабов, что будут проверять вино на наличие яда.\n";
	std::cout << "\nЗадание №5 выполнил Борисов Артём, гр. 453502\n";
	std::cout << "—————————————————————————————————————————————\n";
}

void cleanBuf() {
	std::cin.clear();
	std::cin.ignore(1000000, '\n');
}

int countOnes(int x) {
    int bitCount = 0;
    while (x) { // O(log(x))
        if (x & 1) {
            bitCount++;
        }
        x >>= 1;
    }
    return bitCount;
}

void fillgr(int groups[]) {
    groups[0] = 0;
    groups[1] = 32;

    for (int i = 1; i <= 29; ++i) {
        int bits_num = countOnes(i); // O(log(i))
        int step = 0;

        if (bits_num == 1) step = 16;
        else if (bits_num == 2) step = 8;
        else if (bits_num == 3) step = 4;
        else if (bits_num == 4) step = 2;

        groups[i+1] = groups[i] + step;
    }
}

void getOneBit(int x, int positions[], int& total) {
    total = 0;
    int idx = 0;
    while (x > 0) { // O(log(x))
        if (x & 1) {
            positions[total++] = idx;
        }
        x >>= 1;
        idx++;
    }
}

void findgr(const int groups[], bool slaves[], const bool barrels[]) {
    for (int i = 0; i < 29; ++i) { // O(29)
        int bits[5];
        int bitCount = 0;
        getOneBit(i, bits, bitCount); // O(log(i))

        for (int j = 0; j < bitCount; ++j) { // O(log(i))
            for (int k = groups[i]; k < groups[i + 1]; ++k) { // O(groups[i + 1] - groups[i])
                if (!slaves[bits[j]]) {
                    slaves[bits[j]] = barrels[k];
                }
            }
        }
    }
}

int bargr_num(const bool slaves[]) {
    int index = 0;
    int multiplier = 1;
    for (int i = 0; i < 5; ++i) { // O(5)
        index += slaves[i] * multiplier;
        multiplier *= 2;
    }
    return index;
}

void findbar(int index, const int groups[], bool testers[], const bool containers[]) {
    for (int k = groups[index], i = 0; k < groups[index + 1]; ++k, ++i) { // O(divisions[index + 1] - divisions[index])
        int bits[5];
        int bitCount = 0;
        getOneBit(i, bits, bitCount); // O(log(i))

        for (int j = 0; j < bitCount; ++j) { // O(log(i))
            if (!testers[bits[j]]) {
                testers[bits[j]] = containers[k];
            }
        }
    }
}


int check(int n) {
	while (std::cin.fail() || std::cin.peek() != '\n' || n > 240 || n < 0) {
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