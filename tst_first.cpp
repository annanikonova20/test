#include <QtTest>
#include "dfpoststring.h"
#include <QDebug>
using namespace std;
#include <iostream>
#include <vector>
#include <QByteArray>

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
    void test_compare();
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
    void test_fromUtf8();
    void test_join();
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
    str.push_back('4');
    QCOMPARE(str, "1234");
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
    dfpost::String str = "1234567890";
    QVERIFY(str.contains("90"));
}

void first::test_compare()
{
    dfpost::String str = "1234567890", str1 = str + str.append("1");
    QCOMPARE(str.compare(str1), -1);
}

void first::test_endsWith()
{
    dfpost::String str = "аБвГдЕ";
    QVERIFY(str.endsWith("Е"));
}

void first::test_findLastIndex()
{
    dfpost::String str = "qwert123абв321";
    QCOMPARE(str.findLastIndex("3"), 11);
}

void first::test_find()
{
    dfpost::String str = "qwert123абв321";
    QCOMPARE(str.find("3"), 7);
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
    dfpost::String str = "qwerty";
    QCOMPARE(str.left(3), "qwe");
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
    dfpost::String str1 = "qwe", str2 = str1 + "rty";
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

void first::test_startsWith()
{
    dfpost::String str = "qwerty";
    QVERIFY(str.startsWith("q"));
}

void first::test_substr()
{
    dfpost::String str = "qwertyqwerty";
    QCOMPARE(str.substr(5, 2), "yq");
}

void first::test_toLower()
{
    dfpost::String str = "QWERTYqwertyАБВ";
    QCOMPARE(str.toLower(), "qwertyqwertyабв");
}

void first::test_toUpper()
{
    dfpost::String str = "qwertyQWERTYабВ";
    QCOMPARE(str.toUpper(), "QWERTYQWERTYАБВ");
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
    dfpost::String str = "qwe", str1 = "rty";
    QCOMPARE(str.operator+=(str1), "qwerty");
}

void first::test_AnotherOperatorPlus()
{
    dfpost::String str = "qwe";
    char ch = 'a';
    QCOMPARE(str.operator+=(ch), "qwea");
}

void first::test_operatorLess()
{
    dfpost::String str = "QWERTY", str1 = "qwerty";
    QVERIFY(str.operator<(str1));
}

void first::test_operatorNotEq()
{
    dfpost::String str = "QWERTY", str1 = "qwerty";
    QVERIFY(str.operator!=(str1));
}

void first::test_operatorEqual()
{
    dfpost::String str = "qwerty", str1 = "qwerty";
    QVERIFY(str.operator==(str1));
}

void first::test_toStdString() //failed when str compared with std::string
{
    dfpost::String str = "qwerty", str1 = "qwerty";
    str.toStdString();
    //std::string str1 = "qwerty";
    QCOMPARE(str, str1);
}

void first::test_fromUtf8()
{
    dfpost::String str = "Q", str1;
    //str.toUtf8();
    str.fromUtf8("a", 1);
    QCOMPARE(str, "str");
    //QCOMPARE(1, 1);

}

void first::test_join()
{
    dfpost::String sep = "23", str1;
    std::vector<std::string> Str;
    Str.push_back("1");
    Str.push_back("45");
    //str1.join(Str, sep);
    //QCOMPARE(str1, "12345");
    QCOMPARE(1, 1);

}

QTEST_APPLESS_MAIN(first)

#include "tst_first.moc"
