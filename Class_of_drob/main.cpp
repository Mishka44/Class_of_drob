
#include <iostream>
#include <clocale>
#include <Windows.h>
#include "Franction.hpp"






int main()
{
SetConsoleCP(1251);
SetConsoleOutputCP(1251);
setlocale(LC_ALL, "ru");
Franction Number;
Franction Number2(15, 2);
std::cin >> Number;

Number2++;
Franction Number3 = Number + Number2;

std::cout << Number3.Whole_Part();

}


