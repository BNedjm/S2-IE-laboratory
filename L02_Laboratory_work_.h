#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

#ifndef L02H_H
#define L02H_H

#endif // L02H_H

class Rational{
public:
    Rational (int numerator = 0, int denominator = 1);

    void Set_rational(int numerator, int denominator);

    int Get_numerator() const;

    void Set_numerator(int numerator);

    int Get_denominator() const;

    void Set_denominator(int denominator);

    Rational Rational_addition(const Rational &Added) const;

    Rational Rational_subtraction(const Rational &Added) const;

    void display() const;

    //------------------------------------------------------------------------
    Rational operator+(const Rational &rhs) const;
    Rational operator-(const Rational &rhs) const;
    Rational operator*(const Rational &rhs) const;

    friend std::ostream &operator<<(std::ostream &str, Rational &rhs);
    friend std::istream &operator>>(std::istream &str, Rational &rhs);
    //------------------------------------------------------------------------

private:
    int numerator_;
    int denominator_;
};

