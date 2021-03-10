#include "StringCompression.h"

StringCompression::StringCompression(QObject *parent)
    : QObject(parent)
{
}

StringCompression::~StringCompression()
{
}


// For this challenge you will determine the Run Length Encoding of a string.
// The function RunLength(str) take the str parameter being passed and return 
// a compressed version of the string using the Run-length encoding algorithm. 
// This algorithm works by taking the occurrence of each repeating character 
// and outputting that number along with a single character of the repeating 
// sequence. 

// For example: "wwwggopp" would return 3w2g1o2p. The string will not contain 
// any numbers, punctuation, or symbols. 

QString StringCompression::RunLength(QString str)
{
    QString			result;
    int				length = str.length();

    for (int index = 0; index < length; index++)
    {
        int count = 0;

        if (IsRepeatingChar(str, index, count))
        {
            result += QString("%1%2").arg(QString::number(count), QString(str[index]));
            index += count - 1;
        }

        else {
            result += QString("%1%2").arg(QString::number(1), QString(str[index]));

        }
    }

    return result;
}

bool StringCompression::IsRepeatingChar(QString str, int index, int & count)
{
    bool repeating  = false;
    int  length     = str.length();
    count           = 1;

    if (index != length - 1)
    {
        while ((index < length - 1) && (str[index] == str[index + 1]))
        {
            count++;
            index++;
        }
    }

    repeating = (count > 1);

    return repeating;
}
