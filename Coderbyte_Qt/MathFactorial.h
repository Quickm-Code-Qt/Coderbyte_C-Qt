#pragma once

#include <QObject>

class MathFactorial : public QObject
{
    Q_OBJECT

public:
    MathFactorial(QObject *parent = nullptr);
    ~MathFactorial();

    int FirstFactorial(int num);
};
