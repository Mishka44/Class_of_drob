#include "Franction.hpp"



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

