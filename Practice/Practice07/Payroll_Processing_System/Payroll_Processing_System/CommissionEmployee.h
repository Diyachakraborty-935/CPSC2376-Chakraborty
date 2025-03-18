#pragma once
#ifndef COMMISSIONEMPLOYEE_H
#define COMMISSIONEMPLOYEE_H

#include "Employee.h"

class CommissionEmployee : public Employee {
public:
    double baseSalary;
    double salesAmount;
    double commissionRate;

    CommissionEmployee(std::string name, int id, double baseSalary, double salesAmount, double commissionRate)
        : Employee(name, id), baseSalary(baseSalary), salesAmount(salesAmount), commissionRate(commissionRate) {
    }

    double calculateSalary() const override {
        return baseSalary + (salesAmount * commissionRate);
    }

    void displayInfo() const override {
        Employee::displayInfo();
        std::cout << ", Type: Commission, Base Salary: $" << baseSalary << ", Sales: $"
            << salesAmount << ", Commission Rate: " << commissionRate * 100 << "%, Salary: $"
            << calculateSalary() << std::endl;
    }
};

#endif // COMMISSIONEMPLOYEE_H
