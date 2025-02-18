#include <iostream>
#include <iomanip>
double convertTemperature(double temp, char scale = 'F') {
    if (scale == 'F') {
        // Convert Celsius to Fahrenheit
        return (temp * 9.0 / 5.0) + 32;
    }
    else if (scale == 'C') {
        // Convert Fahrenheit to Celsius
        return (temp - 32) * 5.0 / 9.0;
    }
    else {
        std::cerr << "Invalid scale!" << std::endl;
        return 0;
    }
}

int main() {
    int choice;
    double temp;

    std::cout << "1. Convert Celsius to Fahrenheit\n";
    std::cout << "2. Convert Fahrenheit to Celsius\n";
    std::cout << "Choose an option: ";
    std::cin >> choice;

    if (choice == 1) {
        std::cout << "Enter temperature in Celsius: ";
        std::cin >> temp;
        double result = convertTemperature(temp, 'F');
        std::cout << "Converted: " << std::fixed << std::setprecision(2) << result << "°F\n";
    }
    else if (choice == 2) {
        std::cout << "Enter temperature in Fahrenheit: ";
        std::cin >> temp;
        double result = convertTemperature(temp, 'C');
        std::cout << "Converted: " << std::fixed << std::setprecision(2) << result << "°C\n";
    }
    else {
        std::cout << "Invalid choice. Exiting...\n";
    }

    return 0;
}
