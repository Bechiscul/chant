#pragma once
#include <string>
#include <vector>

#include "lexical.hpp"

namespace chant {

    struct token {};

    std::vector<token> tokenize(const std::string& source);
}  // namespace chant