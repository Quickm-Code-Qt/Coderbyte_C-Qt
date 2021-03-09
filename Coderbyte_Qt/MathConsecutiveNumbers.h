#pragma once

#include <QObject>

class MathConsecutiveNumbers : public QObject
{
    Q_OBJECT

public:
    MathConsecutiveNumbers(QObject *parent = nullptr);
    ~MathConsecutiveNumbers();

    int Consecutive(int arr[], unsigned int length);
};
