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

    //!
    //! \brief append Добавление символа в конец строки
    //! \param[in] str Строка, содержащая один символ
    //!
    String &append(const String &str);

    //!
    //! \brief append Добавление символа в конец строки
    //! \param[in] str Символ
    //!
    String &append(String &&str) noexcept;

    //!
    //! \brief clear Очистка строки
    //!
    void clear() noexcept;

    //!
    //! \brief compare Сравнение строк
    //! \return 0 (если строки одинаковы)
    //! \return 1 (если первая строка длиннее второй)
    //! \return -1 (если вторая строка длиннее первой)
    //!
    int compare(const String &other, CaseSensitivity cs = CaseSensitivity::CaseSensitive) const noexcept;

    //!
    //! \brief contains Определяет, содержит ли строка другую строку
    //! \return True (если строка содержит другую строку)
    //! \return False (если не содержит)
    //!
    bool contains(const String &str, CaseSensitivity cs = CaseSensitivity::CaseSensitive) const noexcept;

    const_pointer data() const;
    pointer data();

    //!
    //! \brief endsWith Определяет, заканчивается ли строка символами, указанными в скобках
    //! \return True (если строка заканчивается указанными символами)
    //! \return False (если строка заканчивается другими символами)
    //!
    bool endsWith(const String &s, CaseSensitivity cs = CaseSensitivity::CaseSensitive) const noexcept;

    //!
    //! \brief empty Проверяет, пустая ли строка
    //!
    bool empty() const noexcept;

    //!
    //! \brief isEmpty Проверяет, пустая ли строка
    //!
    bool isEmpty() const noexcept;

    //!
    //! \brief find Ппоиск первого вхождения подстроки в строку
    //! \return Позицию первого вхождения
    //!
    size_type find(const String &value, CaseSensitivity &&sensitivity = CaseSensitivity::CaseSensitive, size_type startIndex = 0) const noexcept;

    //!
    //! \brief findIndex Проверяет, содержится ли данный символ в строке. Проверка начинается с указанной позиции
    //!
    bool findIndex(const String &value, size_type &index, CaseSensitivity &&sensitivity = CaseSensitivity::CaseSensitive, size_type startIndex = 0) const noexcept;

    //!
    //! \brief findLastIndex Находит последнюю позицию на которой встречается подстрока
    //! \return Позицию, с которой начинается подстрока
    //!
    size_type findLastIndex(const String &value, CaseSensitivity &&sensitivity = CaseSensitivity::CaseSensitive, size_type startIndex = npos) const noexcept;

    //!
    //! \brief join Обьединяет строки в одну, помещая между ними разделитель
    //!
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

    //!
    //! \brief left Проверяет, содержится ли данная подстрока в строке левее указанной позиции
    //!
    String left(size_type n = String::npos) const noexcept;

    //!
    //! \brief length Находит длину строки
    //! \return Количество элементов в строке
    //!
    size_type length() const noexcept;

    //!
    //! \brief mid Возвращает подстроку с указанным количеством элементов, которая начинается с указанной позиции
    //! \param[in] position Индекс начала подстроки
    //! \param[in] n Количество элементов подстроки
    //!
    String mid(size_type position, size_type n = String::npos) const noexcept;

    //!
    //! \brief operator= Присваивает строке значение другой строки
    //!
    String &operator=(const String &other) noexcept;

    //!
    //! \brief operator= Присваивает строке указанное значение
    //!
    String &operator=(String &&other) noexcept;

    //!
    //! \brief operator== Проверяет, равны ли строки
    //!
    bool operator==(const String &s) const noexcept;

    //!
    //! \brief operator!= Проверяет, являются ли данные строки неравными
    //!
    bool operator!=(const String &s) const noexcept;

    //!
    //! \brief operator< Проверяет, меньше ли одна строка другой
    //!
    bool operator<(const String &s) const noexcept;

    //!
    //! \brief operator+= Прибавляет к строке другую строку
    //!
    String &operator+=(const String &s) noexcept;

    //!
    //! \brief operator+= Прибавляет к строке другую строку
    //!
    String &operator+=(const char *s) noexcept;

    template <std::size_t N>
    String &operator+=(const char (&s)[N]) noexcept
    {
        return append(fromUtf8(s, N));
    }

    //!
    //! \brief push_back Вставка указанной подстроки в конец строки
    //!
    void push_back(const String &other) noexcept;

    //!
    //! \brief push_back Вставка указанной подстроки в конец строки
    //!
    void push_back(String &&other) noexcept;


    //!
    //! \brief replace Заменяет строку указанной строкой
    //!
    String &replace(const String &before, const String &after, CaseSensitivity cs = CaseSensitivity::CaseSensitive) noexcept;

    //!
    //! \brief replace Начиная с указанной позиции, заменяет часть строки указанной подстрокой строкой
    //!
    String &replace(size_type pos, size_type count, const String &value) noexcept;

    //!
    //! \brief replacedCopy Заменяет строку указанной строкой
    //!
    String replacedCopy(const String &before, const String &after, CaseSensitivity cs = CaseSensitivity::CaseSensitive) const noexcept;

    void reserve(size_type size);

    //!
    //! \brief right Проверяет, содержится ли данная подстрока в строке левее указанной позиции
    //!
    String right(size_type n) const noexcept;

    size_type size() const noexcept;

    //!
    //! \brief split  Возвращает строковый массив, содержащий подстроки данного экземпляра, разделенные элементами заданной строки
    //!
    std::vector<String> split(const String &sep, SplitBehavior behavior = SplitBehavior::KeepEmptyParts,
                              CaseSensitivity cs = CaseSensitivity::CaseSensitive) const noexcept;

    //!
    //! \brief split  Возвращает строковый массив, содержащий подстроки данного экземпляра, разделенные элементами заданной строки
    //!
    std::vector<String> split(const char sep, SplitBehavior behavior = SplitBehavior::KeepEmptyParts,
                              CaseSensitivity cs = CaseSensitivity::CaseSensitive) const noexcept;

    //!
    //! \brief startsWith Определяет, начинается ли строка символами, указанными в скобках
    //!
    bool startsWith(const String &prefix, CaseSensitivity cs = CaseSensitivity::CaseSensitive) const noexcept;

    //!
    //! \brief substr Возвращает подстроку из строки
    //! \param[in] position Индекс начала подстроки
    //! \param[in] n Количество элементов подстроки
    //!
    String substr(size_type position, size_type n = String::npos) const noexcept;

    //!
    //! \brief toLower Переводит все буквы в нижний регистр
    //!
    String toLower() const noexcept;

    //!
    //! \brief toUpper Переводит все буквы в верхний регистр
    //!
    String toUpper() const noexcept;

    //!
    //! \brief toStdString Преобразует строку в std::string
    //!
    std::string toStdString() const noexcept;

    //!
    //! \brief toStdU16String Преобразует строку в std::u16string
    //!
    std::u16string toStdU16String() const noexcept;

    std::string toUtf8() const;

    //!
    //! \brief trimmed Удаляет пробельные символы с начала и конца строки
    //!
    String trimmed() const noexcept;

    //!
    //! \brief truncate Удаление элементов строки правее заданной позиции
    //!
    void truncate(size_type pos);

    //!
    //! \brief fromStdString Преобразует строку std::string в строку dfpost::String
    //!
    static String fromStdString(const std::string &s) noexcept;

    //!
    //! \brief fromStdU16String Преобразует строку std::u16string в строку dfpost::String
    //!
    static String fromStdU16String(const std::u16string &s) noexcept;

    static String fromUtf8(const char *str, size_type size) noexcept;

    //!
    //! \brief fromUtf16 Изменяет кодировку строки с UTF16 на UTF8
    //! \param[in] *unicode Указатель на массив типа const std::uint16_t
    //! \param[in] size Количество элементов в новой строке
    //!
    static String fromUtf16(const std::uint16_t *unicode, size_type size);

    //!
    //! \brief fromUtf16 Изменяет кодировку строки с UTF16 на UTF8
    //! \param[in] *str Указатель на массив типа const char16_t
    //! \param[in] size Количество элементов в новой строке
    //!
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
