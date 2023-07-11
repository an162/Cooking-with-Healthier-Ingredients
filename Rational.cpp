#include "Rational.h"
#include <sstream>
Rational::Rational(int numerator, int denominator) : numerator(numerator), denominator(denominator) {
    reduce();
}

Rational Rational::operator+(const Rational& other) const {
    int resultNumerator = numerator * other.denominator + other.numerator * denominator;
    int resultDenominator = denominator * other.denominator;
    return Rational(resultNumerator, resultDenominator);
}

Rational Rational::operator-(const Rational& other) const {
    int resultNumerator = numerator * other.denominator - other.numerator * denominator;
    int resultDenominator = denominator * other.denominator;
    return Rational(resultNumerator, resultDenominator);
}

Rational Rational::operator*(const Rational& other) const {
    int resultNumerator = numerator * other.numerator;
    int resultDenominator = denominator * other.denominator;
    return Rational(resultNumerator, resultDenominator);
}

Rational Rational::operator/(const Rational& other) const {
    int resultNumerator = numerator * other.denominator;
    int resultDenominator = denominator * other.numerator;
    return Rational(resultNumerator, resultDenominator);
}

void Rational::reduce() {
    int gcdValue = gcd(numerator, denominator);
    numerator /= gcdValue;
    denominator /= gcdValue;

    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
}

int Rational::gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

std::ostream& operator<<(std::ostream& os, const Rational& rational) {
    os << rational.numerator;

    if (rational.denominator != 1) {
        os << "/" << rational.denominator;
    }

    return os;
}

std::istream& operator>>(std::istream& is, Rational& rational) {
    std::string input;
    is >> input;

    // Check if the input is an integer
    bool isInteger = true;
    for (char c : input) {
        if (!std::isdigit(c)) {
            isInteger = false;
            break;
        }
    }

    if (isInteger) {
        int integerValue = std::stoi(input);
        rational = Rational(integerValue, 1);
    } else {
        // Parse the input as a Rational
        std::stringstream ss(input);
        int numerator, denominator;
        char slash;
        ss >> numerator >> slash >> denominator;

        if (slash != '/' || ss.fail()) {
            // Error in input format, set failbit for the stream
            is.setstate(std::ios_base::failbit);
            return is;
        }

        rational = Rational(numerator, denominator);
    }

    return is;
}
