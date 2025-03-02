#include "Fraction.h"
#include <iostream>
#include <stdexcept>
#include <algorithm> // For std::gcd

// Default constructor (Fraction())
Fraction::Fraction() : num(0), den(1) {}

// Parameterized constructor (Fraction(int n, int d))
Fraction::Fraction(int n, int d) {
    if (d == 0) {
        throw std::invalid_argument("Denominator cannot be zero.");
    }
    num = n;
    den = d;
    simplify();
}

// Getters
int Fraction::getNumerator() const {
    return num;
}

int Fraction::getDenominator() const {
    return den;
}

// Setters
void Fraction::setNumerator(int n) {
    num = n;
    simplify();
}

void Fraction::setDenominator(int d) {
    if (d == 0) {
        throw std::invalid_argument("Denominator cannot be zero.");
    }
    den = d;
    simplify();
}

// Simplify the fraction
void Fraction::simplify() {
    int gcd_value = std::gcd(num, den);
    num /= gcd_value;
    den /= gcd_value;
    if (den < 0) { // Ensure the denominator is positive
        num = -num;
        den = -den;
    }
}

// Arithmetic operators
Fraction operator+(const Fraction& lhs, const Fraction& rhs) {
    int numerator = lhs.num * rhs.den + rhs.num * lhs.den;
    int denominator = lhs.den * rhs.den;
    return Fraction(numerator, denominator);
}

Fraction operator-(const Fraction& lhs, const Fraction& rhs) {
    int numerator = lhs.num * rhs.den - rhs.num * lhs.den;
    int denominator = lhs.den * rhs.den;
    return Fraction(numerator, denominator);
}

Fraction operator*(const Fraction& lhs, const Fraction& rhs) {
    int numerator = lhs.num * rhs.num;
    int denominator = lhs.den * rhs.den;
    return Fraction(numerator, denominator);
}

Fraction operator/(const Fraction& lhs, const Fraction& rhs) {
    if (rhs.num == 0) {
        throw std::invalid_argument("Cannot divide by zero.");
    }
    int numerator = lhs.num * rhs.den;
    int denominator = lhs.den * rhs.num;
    return Fraction(numerator, denominator);
}

// Overload << operator to print the fraction
std::ostream& operator<<(std::ostream& os, const Fraction& fraction) {
    os << fraction.num << "/" << fraction.den;
    return os;
}
