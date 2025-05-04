#include "TextProcessor.h"

void TextProcessor::setStrategy(std::shared_ptr<TextFilterStrategy> newStrategy) {
    strategy = newStrategy;
}

std::string TextProcessor::processText(const std::string& text) {
    return strategy->apply(text);
}
