#ifndef FRANCTION_HPP
#define FRANCTION_HPP
#include <iostream>
#include <clocale>
#include <Windows.h>

class Franction {
public:
    Franction(int NewChisl, int NewZnam) :chisl_(NewChisl), znam_(NewZnam) {}

    void show() {
        std::cout << "Ваша текущая дробь:  " << this->chisl_ << '/' << this->znam_ << "\n";
    }

    Franction Summ(Franction& obj);

    Franction Subtraction(const Franction& obj);

    Franction Multiplication(const Franction& obj);

    Franction Division(const Franction& obj);

    int Nod(int a, int b);

    void Reduction() {
        int a = Nod(this->chisl_, this->znam_);
        this->chisl_ = this->chisl_ / a;
        this->znam_ = this->znam_ / a;
    }

private:
    int chisl_;
    int znam_;




};

#endif