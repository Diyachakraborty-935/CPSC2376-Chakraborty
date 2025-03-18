#pragma once
#ifndef HOURLYEMPLOYEE_H
#define HOURLYEMPLOYEE_H

#include "Employee.h"

class HourlyEmployee : public Employee {
public:
    double hourlyRate;
    int hoursWorked;

    HourlyEmployee(std::string name, int id, double hourlyRate, int hoursWorked)
        : Employee(name, id), hourlyRate(hourlyRate), hoursWorked(hoursWorked) {
    }

    double calculateSalary() const override {
        return hourlyRate * hoursWorked;
    }

    void displayInfo() const override {
        Employee::displayInfo();
        std::cout << ", Type: Hourly, Hours Worked: " << hoursWorked << ", Hourly Rate: $"
            << hourlyRate << ", Salary: $" << calculateSalary() << std::endl;
    }
};

#endif // HOURLYEMPLOYEE_H
