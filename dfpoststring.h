#pragma once

// TODO: убрать зависимость от QString
#include <QString>
#include <string>
#include <vector>
#include "dfpostcore_export.h"

namespace dfpost {

enum class CaseSensitivity {
    CaseInsensitive,
    CaseSensitive
};

//!
//! \brief The SplitBehavior enum - это перечисление определяет, как функции split() должны вести
//! себя по отношению к пустым строкам
//!
enum class SplitBehavior {
    KeepEmptyParts, ///< Если поле пусто, сохранить его в результате.
    SkipEmptyParts  ///< Если поле пусто, не включать его в результат.
};

//!
//! \brief The String class - представляет символьную строку Unicode.
//! \details
//!
class DFPOSTCORE_EXPORT String
{
public:

    // STL compatibility
    using size_type = std::u16string::size_type;
    using difference_type = std::u16string::difference_type;
    using value_type = std::u16string::value_type;
    using const_reference = const value_type &;
    using reference = value_type &;
    using pointer = value_type *;
    using const_pointer = const value_type *;

    String() = default;
    String(const String &other) noexcept;
    String(String &&other) noexcept;
    String(const char *str) noexcept;
    String(char ch) noexcept;

    static constexpr auto npos {std::u16string::npos};

    String &append(const String &str);
    String &append(String &&str) noexcept;

    void clear() noexcept;

    int compare(const String &other, CaseSensitivity cs = CaseSensitivity::CaseSensitive) const noexcept;

    bool contains(const String &str, CaseSensitivity cs = CaseSensitivity::CaseSensitive) const noexcept;

    const_pointer data() const;
    pointer data();

    bool endsWith(const String &s, CaseSensitivity cs = CaseSensitivity::CaseSensitive) const noexcept;

    bool empty() const noexcept;
    bool isEmpty() const noexcept;

    size_type find(const String &value, CaseSensitivity &&sensitivity = CaseSensitivity::CaseSensitive, size_type startIndex = 0) const noexcept;
    bool findIndex(const String &value, size_type &index, CaseSensitivity &&sensitivity = CaseSensitivity::CaseSensitive, size_type startIndex = 0) const noexcept;
    size_type findLastIndex(const String &value, CaseSensitivity &&sensitivity = CaseSensitivity::CaseSensitive, size_type startIndex = npos) const noexcept;

    static String join(const std::vector<String> &stringList, const dfpost::String & sep) noexcept;

//    template <typename StringsContainer>
//    static String join(StringsContainer &&container, const String &separator) noexcept
//    {
//        static_assert(std::is_same<typename StringsContainer::value_type, String>::value,
//                "dfpost::join container::value_type != dfpost::String");

//        auto accumulatedSize = [](const StringsContainer &list, String::size_type seplen)
//        {
//            String::size_type result {0};
//            if (!list.empty()) {
//                for (const auto &e : list)
//                    result += e.size() + seplen;
//                result -= seplen;
//            }
//            return result;
//        };

//        String result;
//        if (!container.empty()) {
//            result.reserve(accumulatedSize(container, separator.size()));
//            const auto end = container.end();
//            auto it = container.begin();
//            result += std::move(*it);
//            while (++it != end) {
//                result += separator;
//                result += std::move(*it);
//            }
//        }
//        return result;
//    }

    String left(size_type n = String::npos) const noexcept;

    size_type length() const noexcept;

    String mid(size_type position, size_type n = String::npos) const noexcept;

    String &operator=(const String &other) noexcept;
    String &operator=(String &&other) noexcept;
    bool operator==(const String &s) const noexcept;
    bool operator!=(const String &s) const noexcept;
    bool operator<(const String &s) const noexcept;
    String &operator+=(const String &s) noexcept;
    String &operator+=(const char *s) noexcept;

    template <std::size_t N>
    String &operator+=(const char (&s)[N]) noexcept
    {
        return append(fromUtf8(s, N));
    }

    void push_back(const String &other) noexcept;
    void push_back(String &&other) noexcept;

    String &replace(const String &before, const String &after, CaseSensitivity cs = CaseSensitivity::CaseSensitive) noexcept;
    String &replace(size_type pos, size_type count, const String &value) noexcept;
    String replacedCopy(const String &before, const String &after, CaseSensitivity cs = CaseSensitivity::CaseSensitive) const noexcept;

    void reserve(size_type size);

    String right(size_type n) const noexcept;

    size_type size() const noexcept;

    std::vector<String> split(const String &sep, SplitBehavior behavior = SplitBehavior::KeepEmptyParts,
                              CaseSensitivity cs = CaseSensitivity::CaseSensitive) const noexcept;

    std::vector<String> split(const char sep, SplitBehavior behavior = SplitBehavior::KeepEmptyParts,
                              CaseSensitivity cs = CaseSensitivity::CaseSensitive) const noexcept;

    bool startsWith(const String &prefix, CaseSensitivity cs = CaseSensitivity::CaseSensitive) const noexcept;

    String substr(size_type position, size_type n = String::npos) const noexcept;

    String toLower() const noexcept;
    String toUpper() const noexcept;

    std::string toStdString() const noexcept;
    std::u16string toStdU16String() const noexcept;

    std::string toUtf8() const;

    String trimmed() const noexcept;

    void truncate(size_type pos);

    static String fromStdString(const std::string &s) noexcept;
    static String fromStdU16String(const std::u16string &s) noexcept;

    static String fromUtf8(const char *str, size_type size) noexcept;
    static String fromUtf16(const std::uint16_t *unicode, size_type size);
    static String fromUtf16(const char16_t *str, size_type size);

private:
    QString m_data;
};

DFPOSTCORE_EXPORT const String operator+(const String &s1, const String &s2) noexcept;
DFPOSTCORE_EXPORT String operator+(const String &s1, const char s2) noexcept;
DFPOSTCORE_EXPORT String operator+(const char s1, const String &s2) noexcept;

template <std::size_t N>
const String operator+(const String &s1, const char (&s2)[N]) noexcept
{
    String res {s1};
    res += s2;
    return res;
}

}

namespace std {
    template<>
    struct hash<dfpost::String>
    {
        inline std::size_t operator()(const dfpost::String &str) const noexcept
        {
            return hash<decltype(str.toStdU16String())>{}(str.toStdU16String());
        }
    };
}
