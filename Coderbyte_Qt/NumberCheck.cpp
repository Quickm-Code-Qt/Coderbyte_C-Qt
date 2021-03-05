#include "NumberCheck.h"

NumberCheck::NumberCheck(QObject *parent)
    : QObject(parent)
{
}

NumberCheck::~NumberCheck()
{
}

// Have the function CheckNums(num1, num2) take both parameters being passed 
// and return the string true if num2 is greater than num1, otherwise return 
// the string false.If the parameter values are equal to each other then 
// return the string - 1.

QString NumberCheck::checkNums(int num1, int num2)
{
    QString result;

    if (num1 > num2)
        result = "false";
    else if (num2 > num1)
        result = "true";
    else
        result = "-1";

    return result;
}