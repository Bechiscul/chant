#include <algorithm>
#include <iostream>

#include "chant/tokenizer.hpp"

int32_t main() { 
	const std::string source = "     //";
    const auto tokens = chant::tokenize(source);

    for (const auto& token : tokens) {
        std::cout << chant::token_type_to_string(token.type) << '\n';
    }
}