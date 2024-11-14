#include "../include/Rational.h"
#include "../include/Validation.h"  // Include the header for validation functions
#include <iostream>
#include <string>

int main() {
    char choice;
    do {
        std::string input1, input2;

        // Get the first rational number
        do {
            std::cout << "Enter the first rational number (or whole number): ";
            std::cin >> input1;
            if (!isValidRationalInput(input1)) {
                std::cout << "Invalid input. Please enter a rational number in the form 'a/b' or 'a'." << std::endl;
            }
        } while (!isValidRationalInput(input1));

        Rational r1;
        if (input1.find('/') != std::string::npos) {
            r1 = Rational(input1);
        } else {
            int wholeNumber = std::stoi(input1);
            r1 = Rational(wholeNumber);
        }

        std::cout << "========================" << std::endl;
        std::cout << "First Rational Number: " << r1 << std::endl;
        std::cout << "========================" << std::endl;

        // Get the second rational number
        do {
            std::cout << "Enter the second rational number (or whole number): ";
            std::cin >> input2;
            if (!isValidRationalInput(input2)) {
                std::cout << "Invalid input. Please enter a rational number in the form 'a/b' or 'a'." << std::endl;
            }
        } while (!isValidRationalInput(input2));

        Rational r2;
        if (input2.find('/') != std::string::npos) {
            r2 = Rational(input2);
        } else {
            int wholeNumber = std::stoi(input2);
            r2 = Rational(wholeNumber);
        }

        std::cout << "========================" << std::endl;
        std::cout << "Second Rational Number: " << r2 << std::endl;
        std::cout << "========================" << std::endl;

        // Demonstrate arithmetic operations
        std::cout << "Addition (" << r1 << " + " << r2 << "): " << std::endl;
        std::cout << "Result: " << r1 + r2 << std::endl;

        std::cout << "========================" << std::endl;

        std::cout << "Subtraction (" << r1 << " - " << r2 << "): " << std::endl;
        std::cout << "Result: " << r1 - r2 << std::endl;

        std::cout << "========================" << std::endl;

        std::cout << "Multiplication (" << r1 << " * " << r2 << "): " << std::endl;
        std::cout << "Result: " << r1 * r2 << std::endl;

        std::cout << "========================" << std::endl;

        std::cout << "Division (" << r1 << " / " << r2 << "): " << std::endl;
        std::cout << "Result: " << r1 / r2 << std::endl;

        std::cout << "========================" << std::endl;

        // Demonstrate comparison operations
        std::cout << "Comparison Results:" << std::endl;
        std::cout << "========================" << std::endl;
        std::cout << "Greater than (>): " << (r1 > r2 ? "true" : "false") << std::endl;
        std::cout << "Less than (<): " << (r1 < r2 ? "true" : "false") << std::endl;
        std::cout << "Equal (==): " << (r1 == r2 ? "true" : "false") << std::endl;
        std::cout << "========================" << std::endl;

        // Ask the user if they want to perform another calculation with validation
        do {
            std::cout << "Do you want to perform another calculation? (y/n): ";
            std::cin >> choice;
            if (!isValidContinueChoice(choice)) {
                std::cout << "Invalid input. Please enter 'y' or 'n'." << std::endl;
            }
        } while (!isValidContinueChoice(choice));

        std::cout << std::endl;

    } while (choice == 'y' || choice == 'Y');

    std::cout << "Goodbye!" << std::endl;
    return 0;
}
