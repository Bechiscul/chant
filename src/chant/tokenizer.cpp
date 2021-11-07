#include "chant/tokenizer.hpp"

#include <algorithm>
#include <format>
#include <iostream>
#include <stdexcept>

#include "chant/lexical.hpp"

namespace chant {
    std::vector<token> tokenizer::tokenize(const std::string_view& source) {
        std::vector<token> tokens;
        tokens.reserve(source.size());

        const std::optional<token> token;

        while (eat()) {
            while (token = eat_token()) {
                tokens.emplace_back(*token);
            }

            if (!token) {
                // Try to fix the token to continue tokenizing. If not doable stop. Eg. insert a missing " or invalid character.
            }
        }

        return tokens;
    }
} // namespace chant

// std::vector<chant::token> chant::tokenize(const std::string &source) {
//     const auto source_view = std::string_view(source);

//     auto tokens = std::vector<token>();

//     // TODO: Count the amount of tokens without whitespace and end of lines.
//     tokens.reserve(source.size());

//     for (size_t i = 0; i < source.size(); ++i) {
//         if (is_string(source_view, i)) {
//             const auto x = scan_string(source_view, i);
//             std::cout << *x << '\n';

//         } else if (is_digit(source_view, i)) {
//             scan_();

//         } else if (is_eof(source_view, i)) {
//             break;

//         } else if (is_whitespace(source_view, i) || is_eol(source_view, i)) {
//             continue;

//         } else {
//             const auto message = std::format("Unknown token: '{}'!", source[i]);
//             std::cout << source[i] << '\n';
//             throw std::runtime_error(message);
//         }
//     }

//     return tokens;
// }