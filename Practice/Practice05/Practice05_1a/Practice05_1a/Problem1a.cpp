#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers;
    int num;
    char choice;

    // Taking user input for a list of integers
    std::cout << "Enter integers (type 'n' to stop):" << std::endl;
    do {
        std::cin >> num;
        numbers.push_back(num);
        std::cout << "Do you want to enter another number? (y/n): ";
        std::cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    // Printing the list of numbers using iterators
    std::cout << "The numbers you entered are: ";
    for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Finding the sum of even numbers using iterators
    int even_sum = 0;
    for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        if (*it % 2 == 0) {
            even_sum += *it;
        }
    }

    // Printing the sum of even numbers
    std::cout << "The sum of even numbers is: " << even_sum << std::endl;

    return 0;
}