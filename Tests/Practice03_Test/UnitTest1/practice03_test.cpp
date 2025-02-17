#include "pch.h"
#include <iostream>
#include <cassert>
#include <vector>
#include "mathUtils.h"
void testSumRange() {
    // Test the sumRange function
    assert(mathUtils::sumRange(1, 5) == 15); // Expected sum: 1 + 2 + 3 + 4 + 5 = 15
    assert(mathUtils::sumRange(0, 0) == 0);  // Edge case: empty range
    assert(mathUtils::sumRange(-5, 0) == -15); // Expected sum: -5 + (-4) + (-3) + (-2) + (-1) = -15
    std::cout << "sumRange tests passed!" << std::endl;
}

void testContainsNegative() {
    // Test the containsNegative function
    std::vector<int> numbers1 = { 1, 2, 3, 4, 5 };
    assert(mathUtils::containsNegative(numbers1) == false); // No negative numbers

    std::vector<int> numbers2 = { 1, -2, 3, 4, 5 };
    assert(mathUtils::containsNegative(numbers2) == true); // Contains negative numbers

    std::vector<int> numbers3 = { -1, -2, -3, -4, -5 };
    assert(mathUtils::containsNegative(numbers3) == true); // All numbers are negative

    std::vector<int> numbers4 = {};
    assert(mathUtils::containsNegative(numbers4) == false); // Empty vector, no negative numbers

    std::cout << "containsNegative tests passed!" << std::endl;
}

void testFindMax() {
    // Test the findMax function
    std::vector<int> numbers1 = { 1, 2, 3, 4, 5 };
    assert(mathUtils::findMax(numbers1) == 5); // Maximum value is 5

    std::vector<int> numbers2 = { -1, -2, -3, -4, -5 };
    assert(mathUtils::findMax(numbers2) == -1); // Maximum value is -1 (least negative)

    std::vector<int> numbers3 = { 5 };
    assert(mathUtils::findMax(numbers3) == 5); // Single-element vector

    std::vector<int> numbers4 = {};
#include <stdexcept>  // For std::invalid_argument
    int mathUtils::findMax(const std::vector<int>&numbers); {
        if (numbers.empty()); {
            throw std::invalid_argument("Cannot find maximum of an empty vector");
        }
        return *std::max_element(numbers.begin(), numbers.end());
    }
    std::cout << "findMax tests passed!" << std::endl;
}

int main() {
    testSumRange();
    testContainsNegative();
    testFindMax();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
