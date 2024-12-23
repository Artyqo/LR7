#pragma once
#include <string>

#ifndef HEAD_H
#define HEAD_H

void userMenu();
int countOnes(int);
void fillgr(int divisions[]);
void getOneBit(int, int positions[], int&);
void findgr(const int divisions[], bool testers[], const bool containers[]);
int bargr_num(const bool slaves[]);
void findbar(int, const int divisions[], bool testers[], const bool containers[]);

int check(int);
void cleanBuf();
std::string CheckUserInput(std::string);

#endif //HEAD_H