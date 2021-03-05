#include "MathFibonacci.h"

MathFibonacci::MathFibonacci(QObject *parent)
    : QObject(parent)
{
}

MathFibonacci::~MathFibonacci()
{
}

QString MathFibonacci::FibonacciChecker(int num)
{
    QString     result;
    bool        isFibonacci = false;

    isFibonacci = isValidFibonacci(1, 1, num);

    result = (isFibonacci) ? "yes" : "no";


    return result;
}

bool MathFibonacci::isValidFibonacci(int x, int y, int num)
{
    bool isFibonacci = false;

    if (num == 0 || num == 1)
    {
        isFibonacci = true;
    }

    else if (x + y == num)
    {
        isFibonacci = true;
    }

    else if (x + y < num)
    {
        isFibonacci = isValidFibonacci(x + y, x, num);
    }

    else
    {
        isFibonacci = false;
    }
    return isFibonacci;
}
