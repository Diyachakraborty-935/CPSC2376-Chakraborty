#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Prompt the user for input
    int n, threshold;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    std::vector<int> numbers(n);
    std::cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << "Enter the threshold value: ";
    std::cin >> threshold;

    // Count how many elements are greater than the threshold using std::count_if
    int count = std::count_if(numbers.begin(), numbers.end(), [threshold](int num) {
        return num > threshold;
        });

    std::cout << "Number of elements greater than " << threshold << ": " << count << std::endl;

    // Remove elements below the threshold using std::remove_if and a lambda function
    auto new_end = std::remove_if(numbers.begin(), numbers.end(), [threshold](int num) {
        return num < threshold;
        });

    // Erase the "removed" elements from the vector
    numbers.erase(new_end, numbers.end());

    // Print the modified list
    std::cout << "Modified list (only elements >= " << threshold << "): ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
