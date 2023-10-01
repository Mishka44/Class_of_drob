
#include <iostream>
#include <clocale>
#include <Windows.h>

class Drob {
private:
    int chisl_;
    int znam_;
public:
    void chisl_and_znam(int NewChisl, int NewZnam) {
        chisl_ = NewChisl;
        znam_ = NewZnam;
    }
    void show()
    {
        std::cout << "Ваша текущая дробь:  " << this->chisl_ << '/' << this->znam_ << "\n";
    }
    Drob Summ(Drob& obj) {
        Drob result;
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
    Drob Subtraction(const Drob& obj) {
        Drob result_of_sub;
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
    Drob Multiplication(const Drob& obj) {
        Drob result_of_Mult;
        result_of_Mult.znam_ = this->znam_ * (obj.znam_);
        result_of_Mult.chisl_ = this->chisl_ * (obj.chisl_);
        result_of_Mult.Reduction();
       
        return result_of_Mult;
    }
    Drob Division(const Drob& obj) {
        Drob result_of_Div;
        
        result_of_Div.znam_ = this->znam_ * (obj.chisl_);
        result_of_Div.chisl_ = this->chisl_ * (obj.znam_);
        result_of_Div.Reduction();
        
        return result_of_Div;
    }
    int Nod(int a, int b) {
        a = abs(a), b = abs(b);
        if (b == 0) return a;
        else return Nod(b, a%b);
    }
    void Reduction() { 
        int a = Nod(this->chisl_, this->znam_);
        this-> chisl_ = this->chisl_ / a;
        this->znam_ = this->znam_ / a;
    }
    

    
    


};




int main()
{
SetConsoleCP(1251);
SetConsoleOutputCP(1251);
setlocale(LC_ALL, "ru");
Drob Number;
Drob Number2;
Number.chisl_and_znam(5, 10);
Number2.chisl_and_znam(1, 4);
Number.show();
Number = Number.Division(Number2);
//Number.Reduction();
//Number = Number.Subtraction(Number2);
//Number = Number.Summ(Number2);

Number.show();

}


