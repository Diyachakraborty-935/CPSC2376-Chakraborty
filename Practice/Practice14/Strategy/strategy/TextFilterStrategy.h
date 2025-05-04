#pragma once
#ifndef TEXTFILTERSTRATEGY_H
#define TEXTFILTERSTRATEGY_H

#include <string>
#include <memory>
#include <algorithm>

// Abstract base class for TextFilter strategy
class TextFilterStrategy {
public:
    virtual ~TextFilterStrategy() = default;
    virtual std::string apply(const std::string& input) const = 0;
};

// Concrete strategy: Reverse
class ReverseFilter : public TextFilterStrategy {
public:
    std::string apply(const std::string& input) const override;
};

// Concrete strategy: Uppercase
class UppercaseFilter : public TextFilterStrategy {
public:
    std::string apply(const std::string& input) const override;
};

// Concrete strategy: Remove Vowels
class RemoveVowelsFilter : public TextFilterStrategy {
public:
    std::string apply(const std::string& input) const override;
};

// Concrete strategy: Censor Bad Words
class CensorBadWordsFilter : public TextFilterStrategy {
public:
    std::string apply(const std::string& input) const override;
};

#endif // TEXTFILTERSTRATEGY_H
