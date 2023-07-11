#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

class Rational {
public:
    Rational(int numerator = 0, int denominator = 1);

    Rational operator+(const Rational& other) const;
    Rational operator-(const Rational& other) const;
    Rational operator*(const Rational& other) const;
    Rational operator/(const Rational& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Rational& rational);
    friend std::istream& operator>>(std::istream& is, Rational& rational);


private:
    int numerator;
    int denominator;

    void reduce();
    int gcd(int a, int b);
};

#endif  // RATIONAL_H
