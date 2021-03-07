#pragma once

#include <QObject>

class TestChallenges : public QObject
{
    Q_OBJECT

public:
    TestChallenges(QObject *parent = nullptr);
    ~TestChallenges();

    void Test_AlphabetSoup();
    void Test_ArithGeo();
    void Test_NumberCheck();
    void Test_Fibonacci();
    void Test_FindIntersection();
    void Test_FirstFactorial();
    void Test_StringReverse();
    void Test_LetterChanges();
    void Test_LetterCapitalize();
    void Test_LongestWord();
    void Test_Palindrome();
    void Test_PowersOfTwo();
    void Test_ProductDigits();
    void Test_OtherProducts();
    void Test_RemoveBrackets();

    protected:
    void Test_PrintArray(int* arr, int length);
    void Test_PrintArray(QStringList strArr);
};
 