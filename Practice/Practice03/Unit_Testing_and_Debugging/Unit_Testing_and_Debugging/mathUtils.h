// mathUtils.h
#pragma once
#include <vector>
class mathUtils {
public:
    static int sumRange(int start, int end);
    int findMax(const std::vector<int>& numbers);

    bool containsNegative(const std::vector<int>& numbers);

};