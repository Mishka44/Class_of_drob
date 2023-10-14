#include "Franction.hpp"
#include <string>


int Franction::GetChisl()
{
    return this->chisl_;
}



int Franction::GetZnam()
{
    return this->znam_;
}

void Franction::Set_Franction(int new_chisl, int new_znam) {
    this->chisl_ = new_chisl;
    this->znam_ = new_znam;
}

bool Franction::Franc_Is_Correct() {
    return chisl_ < znam_;
}

bool Franction::Franction_Is_Not_Correct()
{
    return !Franc_Is_Correct();
}

bool Franction::Frac_Is_Whole() {
    return chisl_ % znam_ == 0;
}



std::ostream& operator <<(std::ostream& out, Franction& obj) {
    out << obj.GetChisl() << "/" << obj.GetZnam();
    return out;
}

std::istream& operator>>(std::istream& in, Franction& obj)
{
    
    in >> obj.chisl_ >> obj.znam_;
    return in;
}

Franction Franction::operator++(int)// инкримент
{
    Franction result{ *this };
    chisl_ += znam_;
    return result;
}
Franction Franction::operator++()// инкримент
{
    chisl_ += znam_;
    return *this;
}

Franction Franction::operator--() //декремент
{
    chisl_ -= znam_;
    return *this;
}


Franction Franction::operator--(int) //декремент
{
    Franction result{ *this };
    chisl_ -= znam_;
    return result;
}

Franction Franction::operator+(const Franction& other) const
{
    Franction result(1, 1);
    if (this->znam_ == other.znam_) {
        result.chisl_ = this->chisl_ + other.chisl_;
        result.znam_ = this->znam_;
    }
    else {
        result.znam_ = (this->znam_ * (other.znam_));
        result.chisl_ = (this->chisl_ * (other.znam_)) + (other.chisl_ * this->znam_);
    }
    result.Reduction();

    return result;
}

Franction Franction::operator-(const Franction& other) const
{
    Franction result_of_sub(1, 1);
    if (this->znam_ == other.znam_) {
        result_of_sub.chisl_ = this->chisl_ - other.chisl_;
        result_of_sub.znam_ = this->znam_;
    }
    else {

        result_of_sub.znam_ = (this->znam_ * (other.znam_));
        result_of_sub.chisl_ = (this->chisl_ * (other.znam_)) - (other.chisl_ * this->znam_);
    }
    result_of_sub.Reduction();

    return result_of_sub;
}

Franction Franction::operator*(const Franction& other) const
{
    Franction result_of_Mult(1, 1);
    result_of_Mult.znam_ = this->znam_ * (other.znam_);
    result_of_Mult.chisl_ = this->chisl_ * (other.chisl_);
    result_of_Mult.Reduction();

    return result_of_Mult;
}

Franction Franction::operator/(const Franction& other) const
{
    Franction result_of_Div(1, 1);

    result_of_Div.znam_ = this->znam_ * (other.chisl_);
    result_of_Div.chisl_ = this->chisl_ * (other.znam_);
    result_of_Div.Reduction();

    return result_of_Div;
}



Franction Franction::Summ(Franction& obj)
{
    Franction result(1, 1);
    if (this->znam_ == obj.znam_) {
        result.chisl_ = this->chisl_ + obj.chisl_;
        result.znam_ = this->znam_;
    }
    else {
        result.znam_ = (this->znam_ * (obj.znam_));
        result.chisl_ = (this->chisl_ * (obj.znam_)) + (obj.chisl_ * this->znam_);
    }
    result.Reduction();

    return result;
}

Franction Franction::Subtraction(const Franction& obj)
{
    Franction result_of_sub(1, 1);
    if (this->znam_ == obj.znam_) {
        result_of_sub.chisl_ = this->chisl_ - obj.chisl_;
        result_of_sub.znam_ = this->znam_;
    }
    else {

        result_of_sub.znam_ = (this->znam_ * (obj.znam_));
        result_of_sub.chisl_ = (this->chisl_ * (obj.znam_)) - (obj.chisl_ * this->znam_);
    }
    result_of_sub.Reduction();

    return result_of_sub;
}

Franction Franction::Multiplication(const Franction& obj)
{
    Franction result_of_Mult(1, 1);
    result_of_Mult.znam_ = this->znam_ * (obj.znam_);
    result_of_Mult.chisl_ = this->chisl_ * (obj.chisl_);
    result_of_Mult.Reduction();

    return result_of_Mult;
}

Franction Franction::Division(const Franction& obj)
{
    Franction result_of_Div(1, 1);

    result_of_Div.znam_ = this->znam_ * (obj.chisl_);
    result_of_Div.chisl_ = this->chisl_ * (obj.znam_);
    result_of_Div.Reduction();

    return result_of_Div;
}

int Franction::Nod(int a, int b)
{
    a = abs(a), b = abs(b);
    if (b == 0) return a;
    else return Nod(b, a % b);
}

void Franction::Reduction()
{
    int a = Nod(this->chisl_, this->znam_);
    this->chisl_ = this->chisl_ / a;
    this->znam_ = this->znam_ / a;
}

void Franction::Inverce_Franc()
{
    Franction tmp(this->chisl_, this->znam_);
    this->chisl_ = tmp.GetZnam();
    this->znam_ = tmp.GetChisl();
    
}

int Franction::Whole_Part()
{
    int res = chisl_ / znam_;
    return res;
}

Franction Franction::FrancPart()
{
    Franction number(chisl_, znam_);
    int point;
    point = number.Whole_Part();
    number.chisl_ = point;
    number.znam_ = point;
    Franction number2(znam_ * number.znam_, znam_ * number.znam_);

    return Franction(chisl_ - number2.chisl_, znam_);
}

const Franction& operator-(const Franction& obj) {
        return Franction(-obj.chisl_, -obj.znam_);
}

const Franction& operator+(const Franction& obj) {
    return Franction(obj.chisl_, obj.znam_);
}
 