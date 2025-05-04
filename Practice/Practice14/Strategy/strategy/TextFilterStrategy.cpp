#include "TextFilterStrategy.h"
#include <string>
#include <algorithm>
#include <vector>
// Reverse Filter
std::string ReverseFilter::apply(const std::string& input) const {
    return std::string(input.rbegin(), input.rend());
}

// Uppercase Filter
std::string UppercaseFilter::apply(const std::string& input) const {
    std::string uppercase = input;
    std::transform(uppercase.begin(), uppercase.end(), uppercase.begin(), ::toupper);
    return uppercase;
}

// Remove Vowels Filter
std::string RemoveVowelsFilter::apply(const std::string& input) const {
    std::string result;
    for (char c : input) {
        if (std::string("aeiouAEIOU").find(c) == std::string::npos) {
            result += c;
        }
    }
    return result;
}

// Censor Bad Words Filter
std::string CensorBadWordsFilter::apply(const std::string& input) const {
    std::string result = input;
    std::vector<std::string> badWords{ "badword1", "badword2" };
    for (const auto& word : badWords) {
        size_t pos = 0;
        while ((pos = result.find(word, pos)) != std::string::npos) {
            result.replace(pos, word.length(), "****");
            pos += 4;
        }
    }
    return result;
}
