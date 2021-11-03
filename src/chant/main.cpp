#include "chant/tokenizer.hpp"

int32_t main() {
    const std::string source = "\"hello\"\n";
    chant::tokenize(source);
}