#include "MathFactorial.h"

MathFactorial::MathFactorial(QObject *parent)
    : QObject(parent)
{
}

MathFactorial::~MathFactorial()
{
}

// Have the function FirstFactorial(num) take the num parameter being passed and 
// return the factorial of it. For example: if num = 4, then your program should 
// return (4 * 3 * 2 * 1) = 24. For the test cases, the range will be between 1 
// and 18 and the input will always be an integer.
int MathFactorial::FirstFactorial(int num)
{
    int factorial = num;

    for (int index = num - 1; index > 1; index--)
    {
        factorial *= index;
    }

    return factorial;
}
