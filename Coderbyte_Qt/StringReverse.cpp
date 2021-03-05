#include "StringReverse.h"

StringReverse::StringReverse(QObject *parent)
    : QObject(parent)
{
}

StringReverse::~StringReverse()
{
}

// Have the function FirstReverse(str) take the str parameter being passed and 
// return the string in reversed order. For example: if the input string is 
// "Hello World and Coders" then your program should return the string 
// sredoC dna dlroW olleH.
QString StringReverse::FirstReverse(QString str)
{
    QString local = str;

    std::reverse(local.begin(), local.end());

    return local;
}
