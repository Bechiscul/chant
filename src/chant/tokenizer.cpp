#include "chant/tokenizer.hpp"

#include <algorithm>
#include <format>
#include <iostream>
#include <stdexcept>

#include "chant/lexical.hpp"

namespace chant {
    std::string token_type_to_string(token_type type) noexcept {
        switch (type) {
            case token_type::ampersand: return "ampersand";
            case token_type::asterisk: return "asterisk";
            case token_type::at: return "at";
            case token_type::bang: return "bang";
            case token_type::block_comment: return "block_comment";
            case token_type::caret: return "caret";
            case token_type::close_brace: return "close_brace";
            case token_type::close_bracket: return "close_bracket";
            case token_type::close_paren: return "close_paren";
            case token_type::colon: return "colon";
            case token_type::comma: return "comma";
            case token_type::dot: return "dot";
            case token_type::equal: return "equal";
            case token_type::greater: return "greater";
            case token_type::identifier: return "identifier";
            case token_type::lesser: return "lesser";
            case token_type::line_comment: return "line_comment";
            case token_type::literal: return "literal";
            case token_type::minus: return "minus";
            case token_type::open_brace: return "open_brace";
            case token_type::open_bracket: return "open_bracket";
            case token_type::open_paren: return "open_paren";
            case token_type::percent: return "percent";
            case token_type::plus: return "plus";
            case token_type::question: return "question";
            case token_type::semicolon: return "semicolon";
            case token_type::slash: return "slash";
            case token_type::whitespace: return "whitespace";
            default: return "unknown";
        }
    }

    std::optional<token> eat_whitespace(tokenizer& tokenizer) noexcept {
        if (auto c = tokenizer.get()) {
            while (is_whitespace(c)) {
                c = tokenizer.next();
            }

            token token = {};
            token.type = token_type::whitespace;
            return token;
        }

        return std::nullopt;
    }

    std::optional<token> eat_string(tokenizer& tokenizer) noexcept {
        if (is_string(tokenizer.get())) {
            for (auto c = tokenizer.get(); tokenizer.peek(); c = tokenizer.next()) {
            }
        }

        return std::nullopt;
    }

    std::optional<token> eat_literal(tokenizer& tokenizer) noexcept {
        if (const auto c = tokenizer.get()) {
            token_literal literal;
            if (is_string(c)) {
                literal.kind = token_literal::literal_kind::string;
                // Scan string
                // for (auto c) } else if (is_digit(c)) {
            }
        }

        return std::nullopt;
    }

    // std::optional<token> tokenizer::eat_comment() noexcept {

    //    return std::optional<token>();
    //}

    std::optional<token> eat_token(tokenizer& tokenizer) noexcept {
        if (const auto c = tokenizer.get()) {
            if (is_literal(c)) {
                return eat_literal(tokenizer);
            } else if (is_whitespace(c)) {
                return eat_whitespace(tokenizer);

            } /*else if (is_comment(c, tokenizer.peek())) {
                return eat_comment(tokenizer);

            }*/
        }

        return std::nullopt;
    }

    std::vector<token> tokenize(const std::string_view& source) {
        tokenizer tokenizer = {.source = source, .index = 0};
        std::vector<token> tokens = {};

        while (tokenizer.peek()) {
            std::optional<token> token;
            while ((token = eat_token(tokenizer))) {
                tokens.emplace_back(std::move(*token));
            }

            if (!token) {
                // TODO
            }
        }

        return tokens;
    }
}  // namespace chant