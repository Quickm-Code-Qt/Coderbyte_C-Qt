#include "StringPeriods.h"

StringPeriod::StringPeriod(QObject *parent)
    : QObject(parent)
{
}

StringPeriod::~StringPeriod()
{
}

// For this challenge you will need to find the smallest repeating substring.

// The function StringPeriods(str) take the str parameter being passed and 
// determine if there is some substring K that can be repeated N > 1 times 
// to produce the input string exactly as it appears. Your program should 
// return the longest substring K, and if there is none it should return 
// the string -1.

// For example: if str is "abcababcababcab" then your program should return 
// abcab because that is the longest substring that is repeated 3 times to 
// create the final string. 

// Another example: if str is "abababababab" then your program should return 
// ababab because it is the longest substring. 

// If the input string contains only a single character, your program should 
// return the string -1.
QString StringPeriod::StringPeriods(QString str)
{
    QString	result = "-1";
    QString	sub;
    int		max_length = -1;


    if (str.length() > 1)
    {
        for (unsigned int i = 0; i < str.length() / 2; i++)
        {
            int len;
            sub = str.mid(0, i + 1);

            len = CheckForMultipleSubstrings(sub, str);

            if (len > max_length)
            {
                max_length = len;
                result = sub;
            }
        }
    }

    return result;
}

int StringPeriod::CheckForMultipleSubstrings(QString sub, QString str)
{
    int		length = -1;
    int		times = str.length() / sub.length();
    QString	temp;

    for (int index = 0; index < times; index++)
    {
        temp.append(sub);
    }

    if (temp == str)
    {
        length = sub.length();
    }

    return length;
}
