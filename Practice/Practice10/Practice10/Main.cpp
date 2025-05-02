#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>

// Define M_PI if it's not available
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Base abstract class
class Shape {
public:
    virtual double getArea() const = 0;
    virtual ~Shape() = default;
};

// Rectangle derived class
class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double getArea() const override {
        return width * height;
    }
};

// Circle derived class
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}
    double getArea() const override {
        return M_PI * radius * radius;
    }
};

// Function to print areas
void printAllAreas(const std::vector<std::unique_ptr<Shape>>& shapes) {
    for (const auto& shape : shapes) {
        std::cout << "Area: " << std::fixed << std::setprecision(4)
            << shape->getArea() << std::endl;
    }
}

int main() {
    std::ifstream inputFile("shapes.txt");
    if (!inputFile) {
        std::cerr << "Failed to open file.\n";
        return 1;
    }

    std::vector<std::unique_ptr<Shape>> shapes;
    std::string line;

    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string type;
        iss >> type;

        if (type == "rectangle") {
            double width, height;
            if (iss >> width >> height) {
                shapes.push_back(std::make_unique<Rectangle>(width, height));
            }
        }
        else if (type == "circle") {
            double radius;
            if (iss >> radius) {
                shapes.push_back(std::make_unique<Circle>(radius));
            }
        }
    }

    printAllAreas(shapes);
    return 0;
}
