#include "../include/Rational.h"
#include "../include/Validation.h"
#include <iostream>
#include <string>

int main() {
    char choice;
    do {
        std::string input1, input2;


        Rational r1;
        do {
            std::cout << "Enter the first rational number (or whole number): ";
            std::cin >> input1;

            if (!isValidRationalInput(input1)) {
                std::cout << "Invalid input. Please enter a valid rational number.\n";
            }
        } while (!isValidRationalInput(input1));

        if (input1.find('/') != std::string::npos) {
            r1 = Rational(input1); // Uses string constructor
        } else {
            int wholeNumber = std::stoi(input1);
            r1 = Rational(wholeNumber); // Uses one-argument constructor
        }

        std::cout << "========================\n";
        std::cout << "First Rational Number: " << r1 << "\n";
        std::cout << "========================\n";


        Rational r2;
        do {
            std::cout << "Enter the second rational number (or whole number): ";
            std::cin >> input2;

            if (!isValidRationalInput(input2)) {
                std::cout << "Invalid input. Please enter a valid rational number.\n";
            }
        } while (!isValidRationalInput(input2));

        if (input2.find('/') != std::string::npos) {
            r2 = Rational(input2); // Uses string constructor
        } else {
            int wholeNumber = std::stoi(input2);
            r2 = Rational(wholeNumber); // Uses one-argument constructor
        }

        std::cout << "========================\n";
        std::cout << "Second Rational Number: " << r2 << "\n";
        std::cout << "========================\n";


        std::cout << "Addition (" << r1 << " + " << r2 << "): " << r1 + r2 << "\n";
        std::cout << "========================\n";

        std::cout << "Subtraction (" << r1 << " - " << r2 << "): " << r1 - r2 << "\n";
        std::cout << "========================\n";

        std::cout << "Multiplication (" << r1 << " * " << r2 << "): " << r1 * r2 << "\n";
        std::cout << "========================\n";

        std::cout << "Division (" << r1 << " / " << r2 << "): " << r1 / r2 << "\n";
        std::cout << "========================\n";


        std::cout << "Comparison Results:\n";
        std::cout << "========================\n";
        std::cout << "Greater than (>): " << (r1 > r2 ? "true" : "false") << "\n";
        std::cout << "Less than (<): " << (r1 < r2 ? "true" : "false") << "\n";
        std::cout << "Equal (==): " << (r1 == r2 ? "true" : "false") << "\n";
        std::cout << "========================\n";


        do {
            std::cout << "Do you want to perform another calculation? (y/n): ";
            std::cin >> choice;
            if (!isValidContinueChoice(choice)) {
                std::cout << "Invalid input. Please enter 'y' or 'n'.\n";
            }
        } while (!isValidContinueChoice(choice));

        std::cout << "\n";

    } while (choice == 'y' || choice == 'Y');

    std::cout << "Goodbye!\n";
    return 0;
}
