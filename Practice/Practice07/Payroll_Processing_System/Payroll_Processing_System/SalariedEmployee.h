#pragma once
#ifndef SALARIEDEMPLOYEE_H
#define SALARIEDEMPLOYEE_H

#include "Employee.h"

class SalariedEmployee : public Employee {
public:
    double monthlySalary;

    SalariedEmployee(std::string name, int id, double monthlySalary)
        : Employee(name, id), monthlySalary(monthlySalary) {
    }

    double calculateSalary() const override {
        return monthlySalary;
    }

    void displayInfo() const override {
        Employee::displayInfo();
        std::cout << ", Type: Salaried, Monthly Salary: $" << monthlySalary << std::endl;
    }
};

#endif // SALARIEDEMPLOYEE_H
