#pragma once
#include <string>

#ifndef HEAD_H
#define HEAD_H

void userMenu();
bool Valid(const std::string &);
std::string reverseCode(const std::string&);
std::string addReverseCode(const std::string&, const std::string&);
std::string Check(std::string);
void cleanBuf();
std::string CheckUserInput(std::string);

#endif //HEAD_H