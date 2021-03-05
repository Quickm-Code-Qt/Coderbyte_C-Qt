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

    protected:
    void Test_PrintArray(int* arr, int length);
};
 