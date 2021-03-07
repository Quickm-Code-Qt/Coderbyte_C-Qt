#include "StringBrackets.h"
#include <QStack>

StringBrackets::StringBrackets(QObject *parent)
    : QObject(parent)
{
}

StringBrackets::~StringBrackets()
{
}

// For this challenge you will determine how to create evenly matched brackets.

// The function RemoveBrackets(str) take the str string parameter being passed, 
// which will contain only the characters "(" and ")", and determine the minimum 
// number of brackets that need to be removed to create a string of correctly 
// matched brackets. 

// For example: if str is "(()))" then your program should return the number 1. 
// The answer could potentially be 0, and there will always be at least one set 
// of matching brackets in the string.

int StringBrackets::RemoveBrackets(QString str)
{
    int value = 0;

    QStack<QChar>	unmatched;

    for (QChar c : str)
    {
        if (c == '(')
        {
            unmatched.push(c);
        }

        // char is ')'
        else
        {
            // check for matching bracket in stack
            if (!unmatched.empty() && unmatched.top() == '(')
            {
                unmatched.pop();
            }
            else
            {
                unmatched.push(c);
            }
        }
    }

    // Stack contains unmatched brackets
    value = unmatched.size();

    return value;
}
