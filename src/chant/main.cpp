#include <algorithm>
#include <iostream>

#include "chant/tokenizer.hpp"

int32_t main() {
    const std::string source = "\"hello\"";
    auto tokenizer = chant::tokenizer();
    auto tokens = tokenizer.tokenize(source);

    for (size_t i = 0; i < tokens.size() && tokens[i].value; ++i) {
        const auto& value = *(tokens[i].value);
        const auto error = dynamic_cast<const chant::token_error*>(value.get());
        if (error) {
            std::cout << error->message;
        }
    }
}