#include "../include/Validation.h"
#include <regex>
#include <cctype>

bool isValidRationalInput(const std::string& input) {
    std::regex rationalPattern(R"(^-?\d+(/-?\d+)?$)");
    return std::regex_match(input, rationalPattern);
}

bool isValidContinueChoice(char choice) {
    return choice == 'y' || choice == 'Y' || choice == 'n' || choice == 'N';
}

bool isValidDenominator(int denominator) {
    return denominator != 0;
}
