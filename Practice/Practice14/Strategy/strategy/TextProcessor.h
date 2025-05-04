#pragma once
#ifndef TEXTPROCESSOR_H
#define TEXTPROCESSOR_H

#include "TextFilterStrategy.h"
#include <memory>

class TextProcessor {
private:
    std::shared_ptr<TextFilterStrategy> strategy;

public:
    void setStrategy(std::shared_ptr<TextFilterStrategy> newStrategy);
    std::string processText(const std::string& text);
};

#endif // TEXTPROCESSOR_H
