#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <memory>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

class Shape {
public:
    virtual double area() const = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override {
        return M_PI * radius * radius;
    }
};

class Square : public Shape {
    double side;
public:
    Square(double s) : side(s) {}
    double area() const override {
        return side * side;
    }
};

class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override {
        return width * height;
    }
};

class ShapeFactory {
public:
    static std::unique_ptr<Shape> createShape(const std::string& type, const std::vector<double>& params) {
        if (type == "circle" && params.size() == 1) {
            return std::make_unique<Circle>(params[0]);
        }
        else if (type == "square" && params.size() == 1) {
            return std::make_unique<Square>(params[0]);
        }
        else if (type == "rectangle" && params.size() == 2) {
            return std::make_unique<Rectangle>(params[0], params[1]);
        }
        else {
            std::cerr << "Invalid shape or parameters: " << type << "\n";
            return nullptr;
        }
    }
};

int main() {
    std::ifstream file("shapes.txt");
    if (!file.is_open()) {
        std::cerr << "Failed to open file 'shapes.txt'\n";
        return 1;
    }

    std::string line;
    std::vector<std::unique_ptr<Shape>> shapes;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string type;
        double param;
        std::vector<double> params;

        iss >> type;
        while (iss >> param) {
            params.push_back(param);
        }

        auto shape = ShapeFactory::createShape(type, params);
        if (shape) {
            shapes.push_back(std::move(shape));
        }
    }

    double totalArea = 0;
    for (const auto& shape : shapes) {
        totalArea += shape->area();
    }

    std::cout << "Total area: " << totalArea << "\n";
    return 0;
}
