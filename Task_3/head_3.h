#pragma once
#include <string>

#ifndef HEAD_H
#define HEAD_H

void userMenu();
long double check(const std::string& x);
std::string* genalpha(long long base, long long& size);
long long stv(const std::string& sym, std::string* alph, long long size);
std::string checkkk(const std::string& x);
std::string vts(long long val, std::string* alph, long long size);
std::string an(const std::string& n1, const std::string& n2, std::string* alph, long long size);
std::string sn(const std::string& n1, const std::string& n2, std::string* alph, long long size);
int int_check(int num);
void cleanBuf();
std::string CheckUserInput(std::string);

#endif //HEAD_H