#include <iostream>
#include "Fraction.h"
#include "MixedFraction.h"

void printMenu() {
    std::cout << "\nCurrent Fraction: ";
    // The current fraction would be managed here
    std::cout << "\nOptions:\n";
    std::cout << "1. Enter a fraction manually\n";
    std::cout << "2. Add a fraction\n";
    std::cout << "3. Subtract a fraction\n";
    std::cout << "4. Multiply by a fraction\n";
    std::cout << "5. Divide by a fraction\n";
    std::cout << "6. Display as Mixed Fraction\n";
    std::cout << "7. Clear Fraction\n";
    std::cout << "8. Exit\n";
}

int main() {
    Fraction currentFraction(0, 1); // Default fraction 0/1
    int choice;

    do {
        printMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            int num, den;
            std::cout << "Enter numerator: ";
            std::cin >> num;
            std::cout << "Enter denominator: ";
            std::cin >> den;
            try {
                currentFraction = Fraction(num, den);
                std::cout << "Fraction set to: " << currentFraction << std::endl;
            }
            catch (const std::exception& e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
            break;
        }
        case 2: {
            int num, den;
            std::cout << "Enter numerator: ";
            std::cin >> num;
            std::cout << "Enter denominator: ";
            std::cin >> den;
            try {
                Fraction newFraction(num, den);
                currentFraction = currentFraction + newFraction;
                std::cout << "New fraction: " << currentFraction << std::endl;
            }
            catch (const std::exception& e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
            break;
        }
              // Handle other operations like subtract, multiply, divide, etc.
        case 6: {
            MixedFraction mixedFraction(currentFraction);
            std::cout << "Mixed Fraction: " << mixedFraction << std::endl;
            break;
        }
        case 7:
            currentFraction = Fraction(0, 1); // Reset to 0/1
            std::cout << "Fraction cleared.\n";
            break;
        case 8:
            std::cout << "Exiting program.\n";
            break;
        default:
            std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 8);

    return 0;
}