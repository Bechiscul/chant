#pragma once
#include <array>
#include <optional>
#include <string>

namespace chant {
    template <typename T>
    constexpr bool is_character(const T& value) noexcept {
        return true;
    }

    template <typename T>
    constexpr bool is_eof(const T& value) noexcept {
        return value == 0x0000 || value == 0x001A;
    }

    template <typename T>
    constexpr bool is_eol(const T& value) noexcept {
        switch (value) {
            case 0x000A: return true;

            case 0x000D: return true;

            case 0x2028: return true;

            case 0x2029: return true;
        }

        return is_eof(value);
    }

    template <typename T>
    constexpr bool is_whitespace(const std::optional<T>& value) noexcept {
        const auto characters = std::array<char, 4>{0x0020, 0x0009, 0x000B, 0x000C};
        return std::ranges::find(characters, value) != characters.end();
    }

    template <typename T>
    constexpr bool is_comment(const std::optional<T>& value,
                              const std::optional<T>& next) noexcept {
        // Comments always consist of 2 characters.
        return value == '/' && (next == '/' || next == '*');
    }

    template <typename T>
    constexpr bool is_digit(const std::optional<T>& value) noexcept {
        return value >= '0' && value <= '9';
    }

    template <typename T>
    constexpr bool is_string(const std::optional<T>& value) noexcept {
        return value == '"';
    }

    template <typename T>
    constexpr bool is_literal(const std::optional<T>& value) noexcept {
        return is_digit<T>(value) || is_string<T>(value);
    }
}  // namespace chant