#pragma once

#include <QObject>

class StringPalindrome : public QObject
{
    Q_OBJECT

public:
    StringPalindrome(QObject *parent = nullptr);
    ~StringPalindrome();

    QString		Palindrome(QString str);

};
