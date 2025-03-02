#include "MixedFraction.h"
#include <iostream>
#include <cmath> // For abs function

// Constructor to initialize a mixed fraction
MixedFraction::MixedFraction(int whole, int n, int d) : Fraction(n, d), whole(whole) {}

// Constructor to convert a Fraction to a MixedFraction
MixedFraction::MixedFraction(const Fraction& fraction) {
    int numerator = fraction.getNumerator();
    int denominator = fraction.getDenominator();

    whole = numerator / denominator; // The whole number part
    numerator = std::abs(numerator % denominator); // Remainder part as numerator

    // Set the simplified fraction part
    *this = Fraction(numerator, denominator);
}

// Overload << operator to print as mixed fraction
std::ostream& operator<<(std::ostream& os, const MixedFraction& mixedFraction) {
    if (mixedFraction.whole != 0) {
        os << mixedFraction.whole << " ";
    }
    os << mixedFraction.getNumerator() << "/" << mixedFraction.getDenominator();
    return os;
}
