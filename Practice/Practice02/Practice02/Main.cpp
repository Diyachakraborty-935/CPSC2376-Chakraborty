#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>
void displayMenu() {
    std::cout << "\nMenu:\n";
    std::cout << "1. Check Balance\n";
    std::cout << "2. Deposit Money\n";
    std::cout << "3. Withdraw Money\n";
    std::cout << "4. Exit\n";
}

bool loadBalance(double& balance) {
    std::ifstream inFile("account_balance.txt");

    if (!inFile) {
        // File doesn't exist, create it and initialize balance to 100.00
        std::ofstream outFile("account_balance.txt");
        if (!outFile) {
            std::cerr << "Error: Unable to create account_balance.txt" << std::endl;
            return false;
        }
        balance = 100.00;
        outFile << balance;
        outFile.close();
        return true;
    }
    else {
        inFile >> balance;
        inFile.close();
        return true;
    }
}

bool saveBalance(double balance) {
    std::ofstream outFile("account_balance.txt");
    if (!outFile) {
        std::cerr << "Error: Unable to save balance to account_balance.txt" << std::endl;
        return false;
    }
    outFile << balance;
    outFile.close();
    return true;
}

bool deposit(double& balance, double amount) {
    if (amount <= 0) {
        std::cout << "Error: Deposit amount must be positive.\n";
        return false;
    }
    balance += amount;
    return true;
}

bool withdraw(double& balance, double amount) {
    if (amount <= 0) {
        std::cout << "Error: Withdrawal amount must be positive.\n";
        return false;
    }
    if (amount > balance) {
        std::cout << "Error: Insufficient funds. Your balance is $" << std::fixed << std::setprecision(2) << balance << ".\n";
        return false;
    }
    balance -= amount;
    return true;
}

int main() {
    double balance;
    if (!loadBalance(balance)) {
        return 1; // Exit on error while loading the balance
    }

    std::cout << "Welcome to Your Bank Account!\n";
    std::cout << "Your current balance is: $" << std::fixed << std::setprecision(2) << balance << "\n";

    int choice;
    double amount;

    while (true) {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        // Validate menu choice
        if (std::cin.fail() || choice < 1 || choice > 4) {
            std::cout << "Error: Invalid choice. Please enter a number between 1 and 4.\n";
            std::cin.clear(); // clear error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
            continue;
        }

        switch (choice) {
        case 1:
            std::cout << "Your current balance is: $" << std::fixed << std::setprecision(2) << balance << "\n";
            break;

        case 2:
            std::cout << "Enter deposit amount: ";
            std::cin >> amount;
            if (deposit(balance, amount)) {
                if (saveBalance(balance)) {
                    std::cout << "Deposit successful. Your new balance is: $" << std::fixed << std::setprecision(2) << balance << "\n";
                }
                else {
                    std::cout << "Error: Could not save the deposit.\n";
                }
            }
            break;

        case 3:
            std::cout << "Enter withdrawal amount: ";
            std::cin >> amount;
            if (withdraw(balance, amount)) {
                if (saveBalance(balance)) {
                    std::cout << "Withdrawal successful. Your new balance is: $" << std::fixed << std::setprecision(2) << balance << "\n";
                }
                else {
                    std::cout << "Error: Could not save the withdrawal.\n";
                }
            }
            break;

        case 4:
            std::cout << "Thank you for using our bank. Goodbye!\n";
            return 0;
        }
    }

    return 0;
}