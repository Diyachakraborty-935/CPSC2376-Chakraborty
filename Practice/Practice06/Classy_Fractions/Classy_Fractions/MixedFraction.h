#pragma once
#ifndef MIXEDFRACTION_H
#define MIXEDFRACTION_H

#include "Fraction.h"

class MixedFraction : public Fraction {
private:
    int whole;  // Whole number part of the mixed fraction

public:
    // Constructors
    MixedFraction(int whole, int n, int d);
    MixedFraction(const Fraction& fraction);

    // Overload << operator to print as mixed fraction
    friend std::ostream& operator<<(std::ostream& os, const MixedFraction& mixedFraction);
};

#endif