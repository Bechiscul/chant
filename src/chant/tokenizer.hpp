#pragma once
#include <memory>
#include <string>
#include <vector>

#include "lexical.hpp"

namespace chant {

    /// The type of the token.
    enum class token_type {
        ampersand,     //< &
        asterisk,      //< *
        at,            //< @
        bang,          //< !
        block_comment, //< A comment spanning multiple lines.
        caret,         //< ^
        close_brace,   //< }
        close_bracket, //< ]
        close_paren,   //< )
        colon,         //< :
        comma,         //< ,
        dot,           //< .
        equal,         //< =
        greater,       //< >
        identifier,    //< An identifier or a keyword.
        lesser,        //< <
        line_comment,  //< A comment spanning an entire single line.
        literal,       //< A literal.
        minus,         //< -
        open_brace,    //< {
        open_bracket,  //< [
        open_parent,   //< (
        percent,       //< %
        plus,          //< +
        question,      //< ?
        semicolon,     //< ;
        slash,         //< /
        whitespace,    //< One or more whitespace characters.

        /// A token which is not recognized.
        unknown = -1
    };

    /// Info about the token.
    struct token_info {
        std::string filename;
        size_t column, line;
    };

    struct token_value {
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
            decimal, // floats
        } kind;
        std::string value;
    };

    struct token_identifier : public token_value {
        std::string value;
    };

    struct token_unknown : public token_value {
        std::string value;
    };

    class tokenizer {
      public:
        std::vector<token> tokenize(const std::string_view& source);

      private:
        using value_type = char;
        constexpr std::optional<value_type> eat() noexcept;
        constexpr std::optional<value_type> prev() noexcept;
        constexpr std::optional<value_type> next() noexcept;

        std::optional<token> eat_whitespace() noexcept;
        std::optional<token> eat_comment() noexcept;

      private:
        std::string_view source_ = "";
        size_t index_ = 0;
    };

    constexpr std::optional<char> tokenizer::eat() noexcept {
        if (index_ != source_.size()) {
            index_ += 1;
            return source_[index_];
        }

        return std::nullopt;
    }

    constexpr std::optional<char> tokenizer::prev() noexcept {
        if (index_ != 0) {
            return source_[index_ - 1];
        }

        return std::nullopt;
    }

    constexpr std::optional<char> tokenizer::next() noexcept {
        if (index_ + 1 != source_.size()) {
            return source_[index_ + 1];
        }

        return std::nullopt;
    }

} // namespace chant