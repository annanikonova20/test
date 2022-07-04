#include <QStringList>
#include "dfpoststring.h"

namespace dfpost {

template <typename FromCast>
inline String::size_type castToStdSizeType(FromCast value)
{
    return std::is_same<String::size_type, FromCast>::value
            ? value
            : static_cast<String::size_type>(value);
}

template <typename FromCast>
inline constexpr QString::size_type castToQstrSizeType(FromCast value)
{
    auto res = std::is_same<QString::size_type, FromCast>::value
                ? value
                : static_cast<QString::size_type>(value);
    return static_cast<QString::size_type>(res);
}

bool String::empty() const noexcept
{
    return m_data.isEmpty();
}

String::size_type String::length() const noexcept
{
    return m_data.length();
}

String String::mid(String::size_type position, String::size_type n) const noexcept
{
    String res;
    res.m_data = m_data.mid(castToQstrSizeType(position), (n == String::npos)
                            ? -1
                            : castToQstrSizeType(n));
    return res;
}

String &String::operator=(const String &other) noexcept
{
    m_data = other.m_data;
    return *this;
}

bool String::operator==(const String &s) const noexcept
{
    return m_data == s.m_data;
}

bool String::operator!=(const String &s) const noexcept
{
    return m_data != s.m_data;
}

bool String::operator<(const String &s) const noexcept
{
    return m_data < s.m_data;
}

String &String::operator+=(const char *s) noexcept
{
    push_back(fromUtf8(s, strlen(s)));
    return *this;
}

void String::push_back(const String &other) noexcept
{
    append(other);
}

void String::push_back(String &&other) noexcept
{
    append(std::move(other));
}

inline auto toQtCaseSensivity(CaseSensitivity &&sensitivity)
{
    switch (sensitivity) {
    case CaseSensitivity::CaseInsensitive:
        return Qt::CaseInsensitive;
    default:
        return Qt::CaseSensitive;
    }
}

String &String::replace(const String &before, const String &after, CaseSensitivity cs) noexcept
{
    m_data.replace(before.m_data, after.m_data, toQtCaseSensivity(std::move(cs)));
    return *this;
}

String &String::replace(String::size_type pos, size_type count, const String &value) noexcept
{
    if (pos == npos)
        return *this;

    auto qCount = castToQstrSizeType(count);

    m_data.replace(castToQstrSizeType(pos), qCount, value.m_data);

    return *this;
}

String String::replacedCopy(const String &before, const String &after, CaseSensitivity cs) const noexcept
{
    String res(*this);
    res.replace(before, after, cs);
    return res;
}

void String::reserve(String::size_type size)
{
    m_data.reserve(castToQstrSizeType(size));
}

String String::right(String::size_type n) const noexcept
{
    String res;
    res.m_data = m_data.right(castToQstrSizeType(n));
    return res;
}

String::size_type String::size() const noexcept
{
    return m_data.size();
}

inline auto toQtSplitBehavior(SplitBehavior &&sensitivity)
{
#if (QT_VERSION >= QT_VERSION_CHECK(5, 14, 0))
    switch (sensitivity) {
    case SplitBehavior::KeepEmptyParts:
        return Qt::KeepEmptyParts;
    default:
        return Qt::SkipEmptyParts;
    }
#else
    switch (sensitivity) {
    case SplitBehavior::KeepEmptyParts:
        return QString::KeepEmptyParts;
    default:
        return QString::SkipEmptyParts;
    }
#endif
}

std::vector<String> String::split(const String &sep, SplitBehavior behavior, CaseSensitivity cs) const noexcept
{
    auto stringList = m_data.split(sep.m_data, toQtSplitBehavior(std::move(behavior)), toQtCaseSensivity(std::move(cs)));

    std::vector<String> res;
    while (stringList.size() > 0) {
        String item;
        item.m_data = stringList.takeFirst();
        res.emplace_back(std::move(item));
    }

    return res;
}

std::vector<String> String::split(const char sep, SplitBehavior behavior, CaseSensitivity cs) const noexcept
{
    auto stringList = m_data.split(sep, toQtSplitBehavior(std::move(behavior)), toQtCaseSensivity(std::move(cs)));

    std::vector<String> res;
    while (stringList.size() > 0) {
        String item;
        item.m_data = stringList.takeFirst();
        res.emplace_back(std::move(item));
    }

    return res;
}

bool String::startsWith(const String &prefix, CaseSensitivity cs) const noexcept
{
    return m_data.startsWith(prefix.m_data, toQtCaseSensivity(std::move(cs)));
}

String String::substr(String::size_type position, String::size_type n) const noexcept
{
    return mid(position, n);
}

String String::toLower() const noexcept
{
    String res;
    res.m_data = m_data.toLower();
    return res;
}

String String::toUpper() const noexcept
{
    String res;
    res.m_data = m_data.toUpper();
    return res;
}

bool String::isEmpty() const noexcept
{
    return m_data.isEmpty();
}

String::size_type String::find(const String &value, CaseSensitivity &&sensitivity, String::size_type startIndex) const noexcept
{
    String::size_type res {String::npos};
    findIndex(value, res, std::move(sensitivity), startIndex);

    return res;
}

bool String::findIndex(const String &value, String::size_type &index, CaseSensitivity &&sensitivity, size_type startIndex) const noexcept
{
    auto findedIndex = m_data.indexOf(value.m_data, static_cast<int>(startIndex), toQtCaseSensivity(std::move(sensitivity)));
    if (findedIndex == -1) {
        index = String::npos;
        return false;
    }

    index = castToStdSizeType(findedIndex);

    return true;
}

String::size_type String::findLastIndex(const String &value, CaseSensitivity &&sensitivity, String::size_type startIndex) const noexcept
{
    QString::size_type indexFromEnd = -1;
    if (startIndex != npos)
        indexFromEnd = castToQstrSizeType(startIndex);

    auto findedIndex = m_data.lastIndexOf(value.m_data, indexFromEnd, toQtCaseSensivity(std::move(sensitivity)));
    if (findedIndex == -1)
        return String::npos;

    return castToStdSizeType(findedIndex);
}

static String::size_type accumulatedSize(const std::vector<String> &list, String::size_type seplen)
{
    String::size_type result {0};
    if (!list.empty()) {
        for (const auto &e : list)
            result += e.size() + seplen;
        result -= seplen;
    }
    return result;
}

String String::join(const std::vector<String> &stringList, const String &sep) noexcept
{
    String result;
    if (!stringList.empty()) {
        result.reserve(accumulatedSize(stringList, sep.size()));
        const auto end = stringList.cend();
        auto it = stringList.cbegin();
        result += *it;
        while (++it != end) {
            result += sep;
            result += *it;
        }
    }
    return result;
}

String String::left(String::size_type n) const noexcept
{
    String res;
    res.m_data = m_data.left(n == String::npos ? -1 : castToQstrSizeType(n));
    return res;
}

String String::fromStdString(const std::string &s) noexcept
{
    String res;
    res.m_data = QString::fromStdString(s);
    return res;
}

std::string String::toStdString() const noexcept
{
    return m_data.toStdString();
}

std::u16string String::toStdU16String() const noexcept
{
    return m_data.toStdU16String();
}

String String::fromStdU16String(const std::u16string &s) noexcept
{
    String res;
    res.m_data = QString::fromStdU16String(s);
    return res;
}

String String::fromUtf8(const char *str, String::size_type size) noexcept
{
    String res;

    res.m_data = QString::fromUtf8(str, castToQstrSizeType(size));
    return res;
}

std::string String::toUtf8() const
{
    return m_data.toStdString();
}

String String::trimmed() const noexcept
{
    String res;
    res.m_data = m_data.trimmed();
    return res;
}

String String::fromUtf16(const uint16_t *unicode, String::size_type size)
{
    if (unicode == nullptr)
        return {};

    String res;
    res.m_data = QString::fromUtf16(unicode, castToQstrSizeType(size));

    return res;
}

String String::fromUtf16(const char16_t *str, String::size_type size)
{
    String res;
    res.m_data = QString::fromUtf16(str, castToQstrSizeType(size));

    return res;
}

void String::truncate(String::size_type pos)
{
    m_data.truncate(castToQstrSizeType(pos));
}

String &String::operator+=(const String &s) noexcept
{
    this->m_data.append(s.m_data);
    return *this;
}

//String::const_pointer String::unicode() const
//{
//    return reinterpret_cast<String::const_pointer>(m_data.constData());
//}

String::String(const String &other) noexcept
    : m_data {other.m_data}
{

}

String::String(String &&other) noexcept
    : m_data {std::move(other.m_data)}
{

}

String &String::operator=(String &&other) noexcept
{
    std::swap(m_data, other.m_data);
    return *this;
}

String::String(const char *str) noexcept
    : m_data { QString(str) }
{
}

String::String(char ch) noexcept
    : m_data {QChar(ch)}
{
}

String &String::append(const String &str)
{
    m_data.append(str.m_data);
    return *this;
}

String &String::append(String &&str) noexcept
{
    m_data.append(std::move(str.m_data));
    return *this;
}

void String::clear() noexcept
{
    m_data.clear();
}

int String::compare(const String &other, CaseSensitivity cs) const noexcept
{
    return m_data.compare(other.m_data, toQtCaseSensivity(std::move(cs)));
}

bool String::contains(const String &str, CaseSensitivity cs) const noexcept
{
    return m_data.contains(str.m_data, toQtCaseSensivity(std::move(cs)));
}

String::const_pointer dfpost::String::data() const
{
    return reinterpret_cast<String::const_pointer>(m_data.data());
}

String::pointer String::data()
{
    return reinterpret_cast<String::pointer>(m_data.data());
}

bool String::endsWith(const String &s, CaseSensitivity cs) const noexcept
{
    return m_data.endsWith(s.m_data, toQtCaseSensivity(std::move(cs)));
}

const String operator+(const String &s1, const String &s2) noexcept
{
    String res {s1};
    res += s2;
    return res;
}

String operator+(const String &s1, const char s2) noexcept
{
    String res {s1};
    res += String::fromUtf8(&s2, 1);
    return res;
}

String operator+(const char s1, const String &s2) noexcept
{
    String res {String::fromUtf8(&s1, 1)};
    res += s2;
    return res;
}

}
