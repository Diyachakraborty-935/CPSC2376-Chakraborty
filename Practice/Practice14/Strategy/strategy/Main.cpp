#include <iostream>
#include <memory>
#include "TextProcessor.h"
#include "TextFilterStrategy.h"

int main() {
    // Create an instance of TextProcessor
    TextProcessor processor;

    std::string inputText;
    std::cout << "Enter a sentence: ";
    std::getline(std::cin, inputText);

    int choice;
    do {
        std::cout << "\nChoose a filter strategy:\n";
        std::cout << "1. Reverse\n2. Uppercase\n3. Remove Vowels\n4. Censor Bad Words\n5. Exit\n";
        std::cout << "Your choice: ";
        std::cin >> choice;
        std::cin.ignore();  // To ignore the newline character from the input buffer

        switch (choice) {
        case 1:
            processor.setStrategy(std::make_shared<ReverseFilter>());
            break;
        case 2:
            processor.setStrategy(std::make_shared<UppercaseFilter>());
            break;
        case 3:
            processor.setStrategy(std::make_shared<RemoveVowelsFilter>());
            break;
        case 4:
            processor.setStrategy(std::make_shared<CensorBadWordsFilter>());
            break;
        case 5:
            std::cout << "Exiting program." << std::endl;
            return 0;
        default:
            std::cout << "Invalid choice!" << std::endl;
            continue;
        }

        // Process the input text with the selected strategy
        std::string processedText = processor.processText(inputText);
        std::cout << "Processed Text: " << processedText << std::endl;

    } while (true);

    return 0;
}
