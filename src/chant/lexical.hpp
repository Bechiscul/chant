#pragma once
#include <array>
#include <optional>
#include <string>

namespace chant {
    constexpr bool is_character(const std::string_view& value, size_t index) noexcept {
        return true;
    }

    constexpr bool is_eof(const std::string_view& value, size_t index) noexcept {
        return value[index] == 0x0000 || value[index] == 0x001A;
    }

    constexpr bool is_eol(const std::string_view& value, size_t index) noexcept {
        switch (value[index]) {
            case 0x000A:
                return true;

            case 0x000D:
                return true;

            case 0x2028:
                return true;

            case 0x2029:
                return true;
        }

        return is_eof(value, index);
    }

    constexpr bool is_whitespace(const std::string_view& value, size_t index) noexcept {
        const auto characters = std::array<char, 4>{0x0020, 0x0009, 0x000B, 0x000C};
        return std::ranges::find(characters, value[index]) != characters.end();
    }

    constexpr bool is_comment(const std::string_view& value, size_t index) noexcept {
        // Start of the comments always consist of 2 characters.
        if (value.size() > index + 1 && value[index] == '/') {
            return value[index + 1] == '/' || value[index + 2] == '*';
        }

        return false;
    }

    constexpr bool is_digit(const std::string_view& value, size_t index) noexcept {
        return value[index] >= '0' && value[index] <= '9';
    }

    constexpr bool is_string(const std::string_view& value, size_t index) noexcept {
        return value[index] == '"';
    }

    inline std::optional<std::string> scan_string(const std::string_view& value, size_t& index) {
        const auto string = value.substr(index + 1);
        const auto end = std::ranges::find_if(string, [](const auto& c) { return is_string(&c, 0); });

        if (end == string.end()) {
            return std::nullopt;
        }

        index = end - string.begin() + index + 1;
        return std::string(string.begin(), end);
    }
}  // namespace chant