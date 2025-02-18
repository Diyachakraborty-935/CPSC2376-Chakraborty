#include <iostream>
#include <type_traits>
#include <iomanip> // For setting precision in case of double

// Template function to perform calculations
template <typename T>
T calculate(T num1, T num2, char op) {
    T result;
    switch (op) {
    case '+':
        result = num1 + num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    case '*':
        result = num1 * num2;
        break;
    case '/':
        if (num2 != 0) {
            result = num1 / num2;
        }
        else {
            std::cerr << "Error: Division by zero is not allowed." << std::endl;
            exit(1);
        }
        break;
    default:
        std::cerr << "Error: Invalid operation." << std::endl;
        exit(1);
    }
    return result;
}

// Function to check if a string is a valid number (integer or double)
template <typename T>
T getNumberInput() {
    T num;
    std::cin >> num;
    return num;
}

int main() {
    std::cout << "Enter first number: ";
    double firstNumber;
    std::cin >> firstNumber;

    std::cout << "Enter second number: ";
    double secondNumber;
    std::cin >> secondNumber;

    std::cout << "Enter operation (+, -, *, /): ";
    char operation;
    std::cin >> operation;

    // Check if the numbers are integers or doubles
    if (firstNumber == static_cast<int>(firstNumber) && secondNumber == static_cast<int>(secondNumber)) {
        // Use int if both numbers are integers
        int result = calculate(static_cast<int>(firstNumber), static_cast<int>(secondNumber), operation);
        std::cout << "Result: " << result << std::endl;
    }
    else {
        // Use double if either number is a decimal
        double result = calculate(firstNumber, secondNumber, operation);
        std::cout << std::fixed << std::setprecision(2) << "Result: " << result << std::endl;
    }

    return 0;
}