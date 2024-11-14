#include "../include/Rational.h"
#include <iostream>
#include <regex>
#include <stdexcept>
#include <numeric>

// Default constructor
Rational::Rational() : numerator(0), denominator(1) {
    std::cout << "Default Constructor: Initialized to 0/1\n";
}

// One-argument constructor
Rational::Rational(int wholeNumber, bool display) : numerator(wholeNumber), denominator(1) {
    if (display) {
        std::cout << "One-Argument Constructor: Initialized to " << wholeNumber << "/1\n";
    }
}

// Two-argument constructor
Rational::Rational(int num, int denom, bool display) {
    if (denom == 0) throw std::invalid_argument("Denominator cannot be zero.");
    numerator = num;
    denominator = denom;
    if (display) {
        std::cout << "Two-Argument Constructor: Initialized to " << numerator << "/" << denominator << "\n";
    }
    normalize();
}

// String constructor
Rational::Rational(const std::string& input, bool display) {
    std::regex rationalPattern(R"(^(-?\d+)(/(-?\d+))?$)");
    std::smatch match;
    if (std::regex_match(input, match, rationalPattern)) {
        numerator = std::stoi(match[1]);
        denominator = match[3].matched ? std::stoi(match[3]) : 1;
        if (denominator == 0) throw std::invalid_argument("Denominator cannot be zero.");
        if (display) {
            std::cout << "String Constructor: Input: " << input << "\n";
        }
        normalize();
    } else {
        throw std::invalid_argument("Invalid format for rational number. Use 'a/b' or 'a'.");
    }
}

// Normalize function
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

// Overloaded operators
Rational Rational::operator+(const Rational& other) const {
    return Rational(numerator * other.denominator + other.numerator * denominator,
                    denominator * other.denominator);
}

Rational Rational::operator-(const Rational& other) const {
    return Rational(numerator * other.denominator - other.numerator * denominator,
                    denominator * other.denominator);
}

Rational Rational::operator*(const Rational& other) const {
    return Rational(numerator * other.numerator, denominator * other.denominator);
}

Rational Rational::operator/(const Rational& other) const {
    if (other.numerator == 0) {
        throw std::invalid_argument("Cannot divide by zero.");
    }
    return Rational(numerator * other.denominator, denominator * other.numerator);
}

bool Rational::operator>(const Rational& other) const {
    return numerator * other.denominator > other.numerator * denominator;
}

bool Rational::operator<(const Rational& other) const {
    return numerator * other.denominator < other.numerator * denominator;
}

bool Rational::operator==(const Rational& other) const {
    return numerator * other.denominator == other.numerator * denominator;
}

// Overloaded output operator
std::ostream& operator<<(std::ostream& os, const Rational& rational) {
    os << rational.numerator << "/" << rational.denominator;
    return os;
}
