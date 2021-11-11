#pragma once
#include <memory>
#include <string>
#include <vector>

#include "lexical.hpp"

namespace chant {

    /// The type of the token.
    enum class token_type {
        ampersand,      //< &
        asterisk,       //< *
        at,             //< @
        bang,           //< !
        block_comment,  //< A comment spanning multiple lines.
        caret,          //< ^
        close_brace,    //< }
        close_bracket,  //< ]
        close_paren,    //< )
        colon,          //< :
        comma,          //< ,
        dot,            //< .
        equal,          //< =
        greater,        //< >
        identifier,     //< An identifier or a keyword.
        lesser,         //< <
        line_comment,   //< A comment spanning an entire single line.
        literal,        //< A literal.
        minus,          //< -
        open_brace,     //< {
        open_bracket,   //< [
        open_paren,     //< (
        percent,        //< %
        plus,           //< +
        question,       //< ?
        semicolon,      //< ;
        slash,          //< /
        whitespace,     //< One or more whitespace characters.

        /// A token which is not recognized.
        unknown = UINT8_MAX
    };

    std::string token_type_to_string(token_type type) noexcept;

    /// Info about the token.
    struct token_info {
        std::string filename;
        size_t column, line;
    };

    struct token_value {
        constexpr token_value() noexcept = default;

        constexpr virtual ~token_value() noexcept = default;
    };

    struct token {
        token_info info;
        token_type type;
        std::optional<std::unique_ptr<token_value>> value;
    };

    struct token_error : public token_value {
        std::string message;
    };

    struct token_literal : public token_value {
        enum class literal_kind {
            string,
            integer,
            decimal,  // floats
        } kind;
        std::string value;
    };

    struct token_identifier : public token_value {
        std::string value;
    };

    struct token_unknown : public token_value {
        std::string value;
    };

    struct tokenizer {
        std::string_view source;
        size_t index;

        constexpr std::optional<char> get() const noexcept;
        constexpr std::optional<char> peek() const noexcept;
        constexpr std::optional<char> next() noexcept;
    };

    std::vector<token> tokenize(const std::string_view& source);

    constexpr std::optional<char> tokenizer::get() const noexcept {
        if (index + 1 != source.size()) {
            return source[index];
        }

        return std::nullopt;
    }

    /// Peeks at the next character.
    constexpr std::optional<char> tokenizer::peek() const noexcept {
        if (index + 1 != source.size()) {
            return source[index + 1];
        }

        return std::nullopt;
    }

    /// Increments the index and returns the character.
    constexpr std::optional<char> tokenizer::next() noexcept {
        if (index + 1 != source.size()) {
            return source[++index];
        }

        return std::nullopt;
    }

}  // namespace chant