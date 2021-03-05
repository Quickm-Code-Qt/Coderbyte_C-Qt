#pragma once

#include <QObject>

class MathFibonacci : public QObject
{
    Q_OBJECT

public:
    MathFibonacci(QObject *parent = nullptr);
    ~MathFibonacci();

    QString FibonacciChecker(int num);

protected:
    bool		isValidFibonacci(int x, int y, int num);
};
