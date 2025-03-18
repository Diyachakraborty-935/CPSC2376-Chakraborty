#pragma once
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>

class Employee {
public:
    std::string name;
    int id;

    Employee(std::string name, int id) : name(name), id(id) {}

    virtual double calculateSalary() const = 0;
    virtual void displayInfo() const {
        std::cout << "ID: " << id << ", Name: " << name;
    }

    virtual ~Employee() = default;
};

#endif // EMPLOYEE_H
