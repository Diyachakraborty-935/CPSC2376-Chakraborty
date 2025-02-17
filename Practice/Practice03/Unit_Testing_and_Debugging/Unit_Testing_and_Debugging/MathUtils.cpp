// MathUtils.cpp
#include "MathUtils.h"

int mathUtils::sumRange(int start, int end) {
    int sum = 0;
    for (int i = start; i <= end; ++i) {
        sum += i;
    }
    return sum;
}
