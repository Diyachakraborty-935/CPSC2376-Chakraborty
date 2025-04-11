#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <sstream>
#include <iomanip>
#include <cmath>

// Define PI manually
const double PI = 3.14159265358979323846;

// Base class
class Shape {
public:
    virtual double getArea() const = 0;
    virtual ~Shape() = default;
};

// Rectangle class
class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double getArea() const override {
        return width * height;
    }
};

// Circle class
class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double getArea() const override {
        return PI * radius * radius;
    }
};

// Function to print all areas
void printAllAreas(const std::vector<std::unique_ptr<Shape>>& shapes) {
    std::cout << std::fixed << std::setprecision(4);
    for (const auto& shape : shapes) {
        std::cout << "Area: " << shape->getArea() << std::endl;
    }
}

int main() {
    std::ifstream inputFile("shapes.txt");
    if (!inputFile) {
        std::cerr << "Error: Could not open file 'shapes.txt'" << std::endl;
        return 1;
    }

    std::vector<std::unique_ptr<Shape>> shapes;
    std::string line;

    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string shapeType;
        iss >> shapeType;

        if (shapeType == "rectangle") {
            double width, height;
            if (iss >> width >> height) {
                shapes.push_back(std::make_unique<Rectangle>(width, height));
            }
        }
        else if (shapeType == "circle") {
            double radius;
            if (iss >> radius) {
                shapes.push_back(std::make_unique<Circle>(radius));
            }
        }
    }

    printAllAreas(shapes);
    return 0;
}
