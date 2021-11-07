#pragma once
#include <array>
#include <optional>
#include <string>

namespace chant {
    template <typename T> constexpr bool is_character(const T& value) noexcept {
        return true;
    }

    template<typename T>
    constexpr bool is_eof(const T& value) noexcept {
        return value == 0x0000 || value == 0x001A;
    }

    template<typename T>
    constexpr bool is_eol(const T& value) noexcept {
        switch (value) {
        case 0x000A:
            return true;

        case 0x000D:
            return true;

        case 0x2028:
            return true;

        case 0x2029:
            return true;
        }

        return is_eof(value);
    }

    template <typename T> constexpr bool is_whitespace(const T& value) noexcept {
        const auto characters = std::array<char, 4>{0x0020, 0x0009, 0x000B, 0x000C};
        return std::ranges::find(characters, value) != characters.end();
    }

    template <typename T>
    constexpr bool is_comment(const T& value, const std::optional<T>& next) noexcept {
        // Comments always consist of 2 characters.
        return value == "/" && (next == "/" || next == "*");
    }

    template<typename T>
    constexpr bool is_digit(const T& value) noexcept {
        return value >= '0' && value <= '9';
    }

    constexpr std::optional<double> scan_number(const std::string_view& value,
                                                size_t& index) noexcept {
        if (is_digit(value, index)) {

            auto i = index + 1;
            while (is_digit(value, index) || value[i] == '.') {
                i++;
            }
        }

        return std::nullopt;
    }

    constexpr bool is_string(const std::string_view& value, size_t index) noexcept {
        return value[index] == '"';
    }

    inline std::optional<std::string> scan_string(const std::string_view& value,
                                                  size_t& index) {
        const auto string = value.substr(index + 1);
        const auto end =
            std::ranges::find_if(string, [](const auto& c) { return is_string(&c, 0); });

        if (end == string.end()) {
            return std::nullopt;
        }

        index = end - string.begin() + index + 1;
        return std::string(string.begin(), end);
    }
} // namespace chant