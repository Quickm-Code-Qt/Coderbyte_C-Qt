#pragma once

#include <QObject>

class SquareVowels : public QObject
{
    Q_OBJECT

public:
    SquareVowels(QObject *parent = nullptr);
    ~SquareVowels();

    QString VowelSquare(QStringList strArr, int length);

 protected:
    bool    IsVowel(const QChar c);

};
