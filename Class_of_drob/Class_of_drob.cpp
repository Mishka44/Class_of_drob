
#include <iostream>
#include <clocale>
#include <Windows.h>
#include "Franction.hpp"






int main()
{
SetConsoleCP(1251);
SetConsoleOutputCP(1251);
setlocale(LC_ALL, "ru");
Franction Number(3, 2);
Franction Number2(1, 2);;
Number.show();
Number = Number.Division(Number2);
//Number.Reduction();
//Number = Number.Subtraction(Number2);
//Number = Number.Summ(Number2);

Number.show();

}


