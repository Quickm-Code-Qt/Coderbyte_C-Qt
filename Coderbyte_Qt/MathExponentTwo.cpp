#include "MathExponentTwo.h"

MathExponentTwo::MathExponentTwo(QObject *parent)
    : QObject(parent)
{
}

MathExponentTwo::~MathExponentTwo()
{
}

QString MathExponentTwo::powersofTwo(int num)
{
    QString     result  = "false";
    bool        same    = false;

    same = ceil(log2(num)) == floor(log2(num));

    result = (same) ? "true" : "false";

    return result;
}
