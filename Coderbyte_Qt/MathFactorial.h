#pragma once

#include <QObject>

class MathFactorial : public QObject
{
    Q_OBJECT

public:
    MathFactorial(QObject *parent = nullptr);
    ~MathFactorial();

    long long FirstFactorial(int num);
};
