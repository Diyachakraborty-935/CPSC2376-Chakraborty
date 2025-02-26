#include <algorithm>
#include <vector>
#include <iostream>
int main() {
    std::vector<int> numbers = { 10, 23, 5, 47, 18, 34, 89, 2 };
    // Find the largest element using std::max_element
    std::vector<int>::iterator max_it = std::max_element(numbers.begin(), numbers.end());
    if (max_it != numbers.end()) {
        std::cout << "The largest element is: " << *max_it << std::endl;
    }
    else {
        std::cout << "The vector is empty!" << std::endl;
    }

    // Find the smallest element using std::min_element
    std::vector<int>::iterator min_it = std::min_element(numbers.begin(), numbers.end());
    if (min_it != numbers.end()) {
        std::cout << "The smallest element is: " << *min_it << std::endl;
    }
    else {
        std::cout << "The vector is empty!" << std::endl;
    }

    return 0;
}