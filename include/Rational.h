#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <string>

class Rational {
private:
    int numerator;
    int denominator;

    void normalize();

public:
    Rational();
    Rational(int wholeNumber, bool display = true);
    Rational(int num, int denom, bool display = true);
    Rational(const std::string& input, bool display = true);

    int getNumerator() const { return numerator; }
    int getDenominator() const { return denominator; }

    Rational operator+(const Rational &other) const;
    Rational operator-(const Rational &other) const;
    Rational operator*(const Rational &other) const;
    Rational operator/(const Rational &other) const;

    bool operator>(const Rational &other) const;
    bool operator<(const Rational &other) const;
    bool operator==(const Rational &other) const;

    friend std::ostream &operator<<(std::ostream &out, const Rational &r);
};

#endif // RATIONAL_H
