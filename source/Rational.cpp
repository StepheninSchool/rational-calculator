#include "../include/Rational.h"
#include "../include/Validation.h"
#include <iostream>
#include <regex>
#include <stdexcept>
#include <numeric>

Rational::Rational() : numerator(0), denominator(1) {
    std::cout << "Default Constructor: Initialized to 0/1\n";
}

Rational::Rational(int wholeNumber, bool display) : numerator(wholeNumber), denominator(1) {
    if (display) {
        std::cout << "One-Argument Constructor: Initialized to " << wholeNumber << "/1\n";
    }
}
//Source : Clang Tidy
[[maybe_unused]] Rational::Rational(int num, int denom, bool display) {
    if (!isValidDenominator(denom)) throw std::invalid_argument("Denominator cannot be zero.");
    numerator = num;
    denominator = denom;
    if (display) {
        std::cout << "Two-Argument Constructor: Initialized to " << numerator << "/" << denominator << "\n";
    }
    normalize();
}
// Source: https://en.cppreference.com/w/cpp/regex/regex_match
// Source: https://stackoverflow.com/questions/2811031/decimal-or-numeric-values-in-regular-expression-validation
Rational::Rational(const std::string& input, bool display) {

    std::regex rationalPattern(R"(^(-?\d+)(/(-?\d+))?$)");
    std::smatch match;
    if (std::regex_match(input, match, rationalPattern)) {
        numerator = std::stoi(match[1]);
        denominator = match[3].matched ? std::stoi(match[3]) : 1;
        if (!isValidDenominator(denominator)) throw std::invalid_argument("Denominator cannot be zero.");
        if (display) {
            std::cout << "String Constructor: Input: " << input << "\n";
        }
        normalize();
    } else {
        throw std::invalid_argument("Invalid format for rational number. Use 'a/b' or 'a'.");
    }
}
// Source: https://en.cppreference.com/w/cpp/numeric/gcd
void Rational::normalize() {
    int gcdVal = std::gcd(numerator, denominator);
    numerator /= gcdVal;
    denominator /= gcdVal;
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
    std::cout << "After normalization: " << numerator << "/" << denominator << "\n";
}
// Source: https://www.geeksforgeeks.org/operator-overloading-cpp/
Rational Rational::operator+(const Rational& other) const {
    return {numerator * other.denominator + other.numerator * denominator,
                    denominator * other.denominator};
}

Rational Rational::operator-(const Rational& other) const {
    return {numerator * other.denominator - other.numerator * denominator,
                    denominator * other.denominator};
}

Rational Rational::operator*(const Rational& other) const {
    return {numerator * other.numerator, denominator * other.denominator};
}
// Source: https://cplusplus.com/reference/stdexcept/invalid_argument/
Rational Rational::operator/(const Rational& other) const {
    if (other.numerator == 0) {
        throw std::invalid_argument("Cannot divide by zero.");
    }
    return {numerator * other.denominator, denominator * other.numerator};
}

//Source: https://www.cplusplus.com/doc/tutorial/operators/
bool Rational::operator>(const Rational& other) const {
    return numerator * other.denominator > other.numerator * denominator;
}

bool Rational::operator<(const Rational& other) const {
    return numerator * other.denominator < other.numerator * denominator;
}

bool Rational::operator==(const Rational& other) const {
    return numerator * other.denominator == other.numerator * denominator;
}
//source: https://www.learncpp.com/cpp-tutorial/overloading-the-io-operators/
std::ostream& operator<<(std::ostream& out, const Rational& r) {
    out << r.numerator << "/" << r.denominator;
    return out;
}
