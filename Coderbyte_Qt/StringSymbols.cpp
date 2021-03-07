#include "StringSymbols.h"

StringSymbols::StringSymbols(QObject *parent)
    : QObject(parent)
{
}

StringSymbols::~StringSymbols()
{
}

// Have the function SimpleSymbols(str) take the str parameter being passed and 
// determine if it is an acceptable sequence by either returning the string true 
// or false. The str parameter will be composed of + and = symbols with several 
// characters between them (ie. ++d+===+c++==a) and for the string to be true 
// each letter must be surrounded by a + symbol. So the string to the left would 
// be false. The string will not be empty and will have at least one letter.
QString StringSymbols::SimpleSymbols(QString str)
{
    QString result = "false";
    bool   found = false;
    int    length = str.length();

    for (int index = 0; index < length; ++index)
    {
        if (str[index].isLetter())
        {
            if (index != 0 &&
                index != length - 1 &&
                str[index - 1] == '+' &&
                str[index + 1] == '+')
            {
                found = true;
            }

            else
            {
                found = false;
            }
        }
    }
    result = found ? "true" : "false";


    return result;
}
