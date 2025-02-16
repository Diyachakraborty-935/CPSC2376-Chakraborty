#include <iostream>
#include <vector>

// Function that takes a const reference to a vector for read-only access
void printVector(const std::vector<int>& vec) {
    // Loop through the vector and print each element
    for (size_t i = 0; i < vec.size(); ++i) {
        // Use .at() for safe access to vector elements
        std::cout << "Element at index " << i << ": " << vec.at(i) << std::endl;
    }
}

// Function that modifies the vector passed by reference
void modifyVector(std::vector<int>& vec) {
    // Ensure the vector is not empty before modifying
    if (!vec.empty()) {
        // Modify the first element by reference
        vec.at(0) = 100; // Change the first element to 100
    }
}

// Function that demonstrates passing by copy
void addElement(std::vector<int> vec, int value) {
    // Add a new element at the end of the vector
    vec.push_back(value);
    // Print the vector to show the added element
    std::cout << "After adding element " << value << ": ";
    for (const int& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Create a vector of integers
    std::vector<int> numbers = { 1, 2, 3, 4, 5 };

    // Print the vector using a const reference
    std::cout << "Original vector contents:" << std::endl;
    printVector(numbers);

    // Modify the vector by reference
    modifyVector(numbers);
    std::cout << "\nVector after modification:" << std::endl;
    printVector(numbers);

    // Add an element by passing a copy of the vector
    addElement(numbers, 6);

    return 0;
}
