#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <L02h.h>

using namespace std;

//------------------------------------------------------------------------

    Rational Rational::operator+(const Rational &rhs) const {
        return Rational(numerator_ * rhs.denominator_ + rhs.numerator_ * denominator_,
                        denominator_ * rhs.denominator_);
    }

    Rational Rational::operator-(const Rational &rhs) const {
        return Rational(numerator_ * rhs.denominator_ - rhs.numerator_ * denominator_,
                        denominator_ * rhs.denominator_);
    }

    Rational Rational::operator*(const Rational &rhs) const {
        return Rational(numerator_ *rhs.numerator_,
                        denominator_ * rhs.denominator_);
    }

    std::ostream &operator<<(std::ostream &str, Rational &rhs){
        if (rhs.denominator_ == 1) {
            str << rhs.numerator_;
        } else {
            str << rhs.numerator_ << "/" << rhs.denominator_;
        }
        return str;
    }

    std::istream &operator>>(std::istream &str, Rational &rhs){
        string strng;
        str >> strng;
        size_t pos = strng.find('/');
        if (string::npos == pos)
        {
            rhs.numerator_ = stoi(strng);
        }
        else
        {
            rhs.numerator_ = stoi(strng.substr(0,pos));
            strng.erase(0,pos+1);
            rhs.denominator_ = stoi(strng);
        }
        return str;
    }

//------------------------------------------------------------------------

    Rational::Rational (int numerator, int denominator) : numerator_(numerator){
        if (denominator){
            denominator_ = denominator;
        }
        else
            denominator_ = 1;
    }

    void Rational::Set_rational(int numerator, int denominator){
        numerator_ = numerator;
        if (denominator){
            denominator_ = denominator;
        }
        else
            denominator_ = 1;
    }

    int Rational::Get_numerator() const {
        return numerator_;
    }

    void Rational::Set_numerator(int numerator){
        numerator_ = numerator;
    }

    int Rational::Get_denominator() const {
        return denominator_;
    }

    void Rational::Set_denominator(int denominator){
        if (denominator)
            denominator_ = denominator;
    }

    Rational Rational::Rational_addition(const Rational &Added) const {
        return Rational(Added.denominator_*numerator_ + Added.numerator_*denominator_,Added.denominator_*denominator_);
    }

    Rational Rational::Rational_subtraction(const Rational &Added) const {
        return Rational(Added.denominator_*numerator_ - Added.numerator_*denominator_,Added.denominator_*denominator_);
    }

    void Rational::display() const {
        if (denominator_ == 1){
            cout << numerator_;
        }
        else{
            cout << numerator_ << "/" << denominator_;
        }
    }

//------------------------------------------------------------------------
int main()
{
    Rational quarter(1, 4);
    Rational one_third(1, 3);
    Rational random;

    cin >> random;
    cout << "\n\t" << random <<endl;

    Rational add_result, sub_result, mul_result;
    //add_result = one_third.Rational_addition(quarter);
    //sub_result = one_third.Rational_subtraction(quarter);
    add_result = one_third + quarter;
    sub_result = one_third - quarter;
    mul_result = one_third * quarter;

    cout << one_third << " + " << quarter << " = " << add_result << endl;
    //one_third.display(); std::cout << " - "; quarter.display(); std::cout << " = "; sub_result.display(); std::cout << std::endl;
    //one_third.display(); std::cout << " * "; quarter.display(); std::cout << " = "; mul_result.display(); std::cout << std::endl;

    return 0;
}
