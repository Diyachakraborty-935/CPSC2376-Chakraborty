#include "MixedFraction.h"
#include <iostream>
#include <cmath>     // For abs function
#include <numeric>   // For std::gcd (C++17+)

// Constructor to initialize a mixed fraction
MixedFraction::MixedFraction(int whole, int n, int d)
    : Fraction(n, d), whole(whole) {
}

// Constructor to convert a Fraction to a MixedFraction
MixedFraction::MixedFraction(const Fraction& fraction)
    : Fraction(std::abs(fraction.getNumerator() % fraction.getDenominator()),
        fraction.getDenominator()),
    whole(fraction.getNumerator() / fraction.getDenominator()) {
}

// Overload << operator to print as mixed fraction
std::ostream& operator<<(std::ostream& os, const MixedFraction& mixedFraction) {
    if (mixedFraction.whole != 0) {
        os << mixedFraction.whole << " ";
    }
    os << mixedFraction.getNumerator() << "/" << mixedFraction.getDenominator();
    return os;
}
