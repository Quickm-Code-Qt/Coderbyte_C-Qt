#include "MathSummation.h"

MathSummation::MathSummation(QObject *parent)
    : QObject(parent)
{
}

MathSummation::~MathSummation()
{
}

int MathSummation::SimpleAdding(int num)
{
    int result = 0;

    for (int index = 1; index <= num; index++)
    {
        result += index;
    }

    return result;
}
