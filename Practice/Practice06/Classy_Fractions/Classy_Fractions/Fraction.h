#pragma once
#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <stdexcept>

class Fraction {
private:
    int num;  // numerator
    int den;  // denominator

    // Simplifies the fraction by using GCD and ensures denominator is positive
    void simplify();

public:
    // Default constructor (Fraction())
    Fraction();

    // Parameterized constructor (Fraction(int n, int d))
    Fraction(int n, int d);

    // Getters
    int getNumerator() const;
    int getDenominator() const;

    // Setters
    void setNumerator(int n);
    void setDenominator(int d);

    // Arithmetic operators
    friend Fraction operator+(const Fraction& lhs, const Fraction& rhs);
    friend Fraction operator-(const Fraction& lhs, const Fraction& rhs);
    friend Fraction operator*(const Fraction& lhs, const Fraction& rhs);
    friend Fraction operator/(const Fraction& lhs, const Fraction& rhs);

    // Overload << operator to print the fraction
    friend std::ostream& operator<<(std::ostream& os, const Fraction& fraction);
};

#endif
