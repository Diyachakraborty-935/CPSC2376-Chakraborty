#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Employee.h"
#include "SalariedEmployee.h"
#include "HourlyEmployee.h"
#include "CommissionEmployee.h"

int main() {
    std::vector<Employee*> employees;
    std::ifstream file("employees.txt");

    if (!file) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    std::string type;
    while (file >> type) {
        int id;
        std::string name;

        file >> id >> std::ws;  // Skips any leading whitespace
        std::getline(file, name);

        if (type == "Salaried") {
            double salary;
            file >> salary;
            employees.push_back(new SalariedEmployee(name, id, salary));
        }
        else if (type == "Hourly") {
            double rate;
            int hours;
            file >> rate >> hours;
            employees.push_back(new HourlyEmployee(name, id, rate, hours));
        }
        else if (type == "Commission") {
            double baseSalary, sales, commissionRate;
            file >> baseSalary >> sales >> commissionRate;
            employees.push_back(new CommissionEmployee(name, id, baseSalary, sales, commissionRate));
        }
    }

    // Display employee info and salary
    for (const auto& employee : employees) {
        employee->displayInfo();
    }

    // Free dynamically allocated memory
    for (auto& employee : employees) {
        delete employee;
    }

    file.close();
    return 0;
}
