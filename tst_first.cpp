#include <QtTest>
#include "dfpoststring.h"
#include <QDebug>
using namespace std;
#include <iostream>
#include <vector>
#include <QByteArray>
#include <fstream>

// add necessary includes here

class first : public QObject
{
    Q_OBJECT

public:
    first();
    ~first();

private slots:
    void test_case1();
    void test_empty();
    void test_notEmpty();
    void test_clear();
    void test_push_back();
    void test_append();
    void test_contains();
    void test_notContains();
    void test_compareMinusOne();
    void test_compareZero();
    void test_comparePlusOne();
    void test_compareRegister();
    void test_endsWith();
    void test_findLastIndex();
    void test_find();
    void test_findIndex();
    void test_length();
    void test_length0();
    void test_left();
    void test_left1();
    void test_mid();
    void test_mid1();
    void test_replace();
    void test_AnotherReplace();
    void test_replacedCopy();
    void test_right();
    void test_size();
    void test_zeroSize();
    void test_startsWith();
    void test_substr();
    void test_toLower();
    void test_toUpper();
    void test_trimmed();
    void test_truncate();
    void test_operatorPlus();
    void test_AnotherOperatorPlus();
    void test_operatorLess();
    void test_operatorNotEq();
    void test_operatorEqual();
    void test_toStdString();
    void test_join();
    void test_toStdU16String();
    void test_size1();
    void test_fromStdString();
    void test_fromStdU16String();
    void test_split();
    void test_split1();
    void test_join1();
    void test_constructorDefault();
    void test_constructor1();
    void test_constructor2();
    void test_constructor3();
    void test_constructor4();
    void test_fromUtf16();
    void test_fromUtf16Str();
    void test_assignment();
    void test_compare_data();
    void test_compare();
    void test_size0_data();
    void test_size0();

};

first::first()
{

}

first::~first()
{

}

void first::test_case1()
{

    //QVERIFY(false);
    QCOMPARE(1, 1);
}

void first::test_empty()
{
    dfpost::String str;
    QVERIFY(str.isEmpty());
}

void first::test_notEmpty()
{
    dfpost::String str {"qwerty"};
    qDebug() << "step 1";
    QVERIFY(!str.isEmpty());
}

void first::test_clear()
{
    dfpost::String str {"qwerty"};
    QVERIFY(!str.isEmpty());
    str.clear();
    QVERIFY(str.isEmpty());
}

void first::test_push_back()
{
    dfpost::String str = "123";
    str.push_back("45");
    QCOMPARE(str, "12345");
}

void first::test_append()
{
    dfpost::String str;
    str.append("456");
    str.append("7");
    QCOMPARE(str, "4567");
}

void first::test_contains()
{
    dfpost::String str = "qwe rty";
    QVERIFY(str.contains("e r"));
}

void first::test_notContains()
{
    dfpost::String str = "Qwerty";
    QCOMPARE(str.contains("qW"), false);
}

void first::test_compareMinusOne()
{
    dfpost::String str = "1234567890", str1 = str + str.append("1");
    QCOMPARE(str.compare(str1), -1);
}

void first::test_compareZero()
{
    dfpost::String str = "1234567890", str1 = str;
    QCOMPARE(str.compare(str1), 0);
}

void first::test_comparePlusOne()
{
    dfpost::String str = "1234567890", str1 = "1";
    QCOMPARE(str.compare(str1), 1);
}

void first::test_compareRegister()
{
    dfpost::String str = "qwerty", str1 = "Qwerty";
    QCOMPARE(str.compare(str1), 32);
}

void first::test_endsWith()
{
    dfpost::String str = "аБвГдЕ";
    QVERIFY(str.endsWith("дЕ"));
}

void first::test_findLastIndex()
{
    dfpost::String str = "qwert123абв123";
    QCOMPARE(str.findLastIndex("123"), 11);
}

void first::test_find()
{
    dfpost::String str = "qwert12⻰абв321";
    QCOMPARE(str.find("⻰а"), 7);
}

void first::test_findIndex()
{
    dfpost::String str = "qwert123абв321";
    unsigned long long index = 7;
    QVERIFY(str.findIndex("3", index));
}

void first::test_length()
{
    dfpost::String str = "qwert123абв321";
    QCOMPARE(str.length(), 14);
}

void first::test_length0()
{
    dfpost::String str;
    QCOMPARE(str.length(), 0);
}

void first::test_left()
{
    dfpost::String str;
    QCOMPARE(str.left(10), "");
}

void first::test_left1()
{
    dfpost::String str = "みやこqwerty";
    QCOMPARE(str.left(3), "みやこ");
}

void first::test_mid()
{
    dfpost::String str = "qwertyqwerty";
    QCOMPARE(str.mid(5, 2), "yq");
}

void first::test_mid1()
{
    dfpost::String str;
    QCOMPARE(str.mid(5, 2), "");
}

void first::test_replace()
{
    dfpost::String str1 = "QWE", str2 = "qwerty";
    QCOMPARE(str1.replace(str1, str2), "qwerty");
}

void first::test_AnotherReplace()
{
    dfpost::String str1 = "qwerty";
    QCOMPARE(str1.replace(3, 4, "RTY"), "qweRTY");
}

void first::test_replacedCopy()
{
    dfpost::String str1 = "qwe", str2 = str1 + "rty";
    QCOMPARE(str1.replace(str1, str2), "qwerty");
}

void first::test_right()
{
    dfpost::String str = "qwerty";
    QCOMPARE(str.right(2), "ty");
}

void first::test_size()
{
    dfpost::String str = "0123456789";
    QCOMPARE(str.size(), 10);
}

void first::test_zeroSize()
{
    dfpost::String str = "";
    QCOMPARE(str.size(), 0);
}

void first::test_startsWith()
{
    dfpost::String str = "𓀜𓂇qwerty";
    QVERIFY(str.startsWith("𓀜𓂇"));
}

void first::test_substr()
{
    dfpost::String str = "qwertyqwerty";
    QCOMPARE(str.substr(5, 2), "yq");
}

void first::test_toLower()
{
    dfpost::String str = "QWERTYqwertyАБВ☺";
    QCOMPARE(str.toLower(), "qwertyqwertyабв☺");
}

void first::test_toUpper()
{
    dfpost::String str = "☺qwertyQWERTYабВ";
    QCOMPARE(str.toUpper(), "☺QWERTYQWERTYАБВ");
}

void first::test_trimmed()
{
    dfpost::String str = "   qwe rty    ";
    QCOMPARE(str.trimmed(), "qwe rty");
}

void first::test_truncate()
{
    dfpost::String str = "qw erty" ;
    str.truncate(3);
    QCOMPARE(str, "qw ");
}

void first::test_operatorPlus()
{
    dfpost::String str = "qwe", str1 = "rty💮";
    QCOMPARE(str += str1, "qwerty💮");
}

void first::test_AnotherOperatorPlus()
{
    dfpost::String str = "qwe";
    char sym = 'a';
    QCOMPARE(str += sym, "qwea");
}

void first::test_operatorLess()
{
    dfpost::String str = "QWERTY", str1 = "qwerty";
    QVERIFY(str < str1);
}

void first::test_operatorNotEq()
{
    dfpost::String str = "QWERTY", str1 = "qwerty";
    QVERIFY(str != str1);
}

void first::test_operatorEqual()
{
    dfpost::String str = "qwerty", str1 = "qwerty";
    QVERIFY(str == str1);
}

void first::test_toStdString()
{
    dfpost::String str = "qwerty𓅊";
    std::string STD1 = "qwerty𓅊", STD2;
    STD2 = str.toStdString();
    QCOMPARE(STD1, STD2);
}

void first::test_join()
{
    dfpost::String sep = ",";
    std::vector<dfpost::String> source = {"Ivanov", "Ivan"};
    auto result = dfpost::String::join(source, sep);
    QCOMPARE(result, "Ivanov,Ivan");
}

void first::test_toStdU16String()
{
    dfpost::String str = "★qwerty";
    std::u16string STD1 = u"★qwerty", STD2;
    STD2 = str.toStdU16String();
    QCOMPARE(STD1, STD2);
}

void first::test_size1()
{
    dfpost::String str = "𐏕𐎢𒀱";
    QCOMPARE(str.size(), 6);
}

void first::test_fromStdString()
{
    dfpost::String DF1 = "qwerty©", DF2;
    std::string STD1 = "qwerty©";
    QCOMPARE(DF1, DF2.fromStdString(STD1));
}

void first::test_fromStdU16String()
{
    dfpost::String DF1 = "1qwertyΣ", DF2;
    std::u16string STD1 = u"1qwertyΣ";
    QCOMPARE(DF1, DF2.fromStdU16String(STD1));
}

void first::test_split()
{
    dfpost::String str = "123,456", sep = ",";
    std::vector<dfpost::String> str1 = {"123", "456"};
    auto splitResult = str.split(sep);
    QVERIFY(str1 == splitResult);
}

void first::test_split1()
{
    dfpost::String str = "Ivanov,Ivan;Petrov,Petr", sep1 = ';', sep2 = ",";
    std::vector<dfpost::String> res1 = {"Ivanov", "Ivan"}, res2 = {"Petrov", "Petr"};
    auto splitResult = str.split(sep1);
    auto splitRes1 = splitResult[0].split(sep2);
    auto splitRes2 = splitResult[1].split(sep2);
    if (res1 == splitRes1)
        if (res2 == splitRes2)
        QVERIFY(true);
}

void first::test_join1()
{
    dfpost::String sep1 = ",", sep2 = ";";
    std::vector<dfpost::String> source1 = {"Ivanov", "Ivan"}, source2 = {"Petrov", "Petr"}, Res;
    auto result1 = dfpost::String::join(source1, sep1);
    auto result2 = dfpost::String::join(source2, sep1);
    Res.push_back(result1);
    Res.push_back(result2);
    auto finalResult = dfpost::String::join(Res, sep2);
    QCOMPARE(finalResult, "Ivanov,Ivan;Petrov,Petr");
}

void first::test_constructorDefault()
{
    QCOMPARE(dfpost::String(), "");
}

void first::test_constructor1()
{
    QCOMPARE(dfpost::String('q'), 'q');
}

void first::test_constructor2()
{
    char str_source[3] = {'1', '2', '3'};
    char * str_ptr = str_source;
    QCOMPARE(dfpost::String(str_ptr), "123");
}

void first::test_constructor3()
{
    dfpost::String src = "qwerty";
    const dfpost::String &str = src;
    QCOMPARE(dfpost::String(str), "qwerty");
}

void first::test_constructor4()
{
    dfpost::String &&str = "qwerty";
    QCOMPARE(dfpost::String(str), "qwerty");
}

void first::test_fromUtf16()
{
    char16_t str_source[4] = {u'q', u'Ц', u'©', u'©'};
    char16_t * str_ptr = str_source;
    auto res = dfpost::String::fromUtf16(str_ptr, 3);
    QCOMPARE(res, "qЦ©");
}

void first::test_fromUtf16Str()
{
    std::uint16_t str_source[4] = {u'q', u'Ц', u'©', u'w'};
    std::uint16_t * str_ptr = str_source;
    auto res = dfpost::String::fromUtf16(str_ptr, 3);
    QCOMPARE(res, "qЦ©");
}

void first::test_assignment()
{
      dfpost::String str = "qwerty";
      QCOMPARE(str, "qwerty");
}

void first::test_compare_data()
{
    QTest::addColumn<QString>("str1");
    QTest::addColumn<QString>("str2");
    QTest::addColumn<int>("expected");
    QTest::newRow("Compare result Minus One") << "1234567890" << "12345678901" << -1;
    QTest::newRow("Compare result Plus one") << "0" << "" << 1;
    QTest::newRow("Compare result Zero") << "qwerty" << "qwerty" << 0;
    QTest::newRow("Compare Register") << "qwerty" << "Qwerty" << 32;
}

void first::test_compare()
{
    QFETCH(QString, str1);
    QFETCH(QString, str2);
    QFETCH(int, expected);
    QCOMPARE(str1.compare(str2), expected);
}

void first::test_size0_data()
{
    QTest::addColumn<QString>("str");
    QTest::addColumn<int>("expected");
    QTest::newRow("Zero Size") << "" << 0;
    QTest::newRow("Size 1") << "qwerty" << 6;
    QTest::newRow("Size 2") << "𐏕𐎢𒀱" << 6;
}

void first::test_size0()
{
    QFETCH(QString, str);
    QFETCH(int, expected);
    QCOMPARE(str.size(), expected);
}


QTEST_APPLESS_MAIN(first)

#include "tst_first.moc"
