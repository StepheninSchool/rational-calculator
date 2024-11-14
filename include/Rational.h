#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <string>

class Rational {
private:
    int numerator;
    int denominator;
    // Source: https://en.cppreference.com/w/cpp/numeric/gcd (for normalizing using gcd)
    void normalize();

public:
    Rational();
    // Source: https://www.cplusplus.com/doc/tutorial/classes/
    explicit Rational(int wholeNumber, bool display = true);
    [[maybe_unused]] Rational(int num, int denom, bool display = true);
    explicit Rational(const std::string& input, bool display = true);

    // Source: https://www.geeksforgeeks.org/encapsulation-in-cpp/ (Getters and Setters)
    // Source: Clang Tidy
    [[maybe_unused]] [[nodiscard]] int getNumerator() const { return numerator; }
    // Source: Clang Tidy
    [[maybe_unused]] [[nodiscard]] int getDenominator() const { return denominator; }

    Rational operator+(const Rational &other) const;
    Rational operator-(const Rational &other) const;
    Rational operator*(const Rational &other) const;
    Rational operator/(const Rational &other) const;

    bool operator>(const Rational &other) const;
    bool operator<(const Rational &other) const;
    bool operator==(const Rational &other) const;

    // Source: https://www.learncpp.com/cpp-tutorial/93-overloading-the-io-operators/
    friend std::ostream &operator<<(std::ostream &out, const Rational &r);
};

#endif // RATIONAL_H
