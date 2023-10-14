#ifndef FRANCTION_HPP
#define FRANCTION_HPP
#include <iostream>
#include <clocale>
#include <Windows.h>

class Franction {
public:
    Franction() = default;
    Franction(int NewChisl, int NewZnam) :chisl_(NewChisl), znam_(NewZnam) {}
   // explicit Franction(double NewChisl, double NewZnam) :chisl_(NewChisl), znam_(NewZnam) {}

    void show() {
        std::cout << "Ваша текущая дробь:  " << this->chisl_ << '/' << this->znam_ << "\n";
    }
    int GetChisl();

    int GetZnam();

    void Set_Franction(int new_chisl, int new_znam_);


    bool Franc_Is_Correct();

    bool Franction_Is_Not_Correct();

    bool Frac_Is_Whole();


    

    Franction operator++(int);
    Franction operator++();

    Franction operator--(int);
    Franction operator--();

    Franction operator +(const Franction& other)const;
    
    Franction operator -(const Franction& other)const;

    Franction operator *(const Franction& other)const;

    Franction operator /(const Franction& other)const;

    Franction Summ(Franction& obj);

    Franction Subtraction(const Franction& obj);

    Franction Multiplication(const Franction& obj);

    Franction Division(const Franction& obj);

    void Inverce_Franc();

    int Nod(int a, int b);

    int Whole_Part();
    Franction FrancPart();

    void Reduction();

    friend std::istream& operator>>(std::istream&, Franction&);
    friend std::ostream& operator <<(std::ostream& out, Franction&);

    friend const  Franction &operator-(const Franction& obj);
    friend const Franction &operator+(const Franction& obj);

private:
    int chisl_;
    int znam_;

    

};

#endif