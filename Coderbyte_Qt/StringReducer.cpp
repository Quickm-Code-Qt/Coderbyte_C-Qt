#include "StringReducer.h"
#include <QDebug>

StringReducer::StringReducer(QObject *parent)
    : QObject(parent)
{
}

StringReducer::~StringReducer()
{
}

// For this challenge you will manipulate a string of characters using a simple 
// reduction method.

// The function StringReduction(str) take the str parameter being passed and 
// return the smallest number you can get through the following reduction 
// method. The method is: Only the letters a, b, and c will be given in str and 
// you must take two different adjacent characters and replace it with the third. 

// For example "ac" can be replaced with "b" but "aa" cannot be replaced with 
// anything. This method is done repeatedly until the string cannot be further 
// reduced, and the length of the resulting string is to be outputted. 

// For example: if str is "cab", "ca" can be reduced to "b" and you get "bb" (you 
// can also reduce it to "cc"). The reduction is done so the output should be 2. 
// If str is "bcab", "bc" reduces to "a", so you have "aab", then "ab" reduces to 
// "c", and the final string "ac" is reduced to "b" so the output should be 1. 

int StringReducer::StringReduction(QString str)
{
    int		result      = -1;
    QString	localStr    = str;
    int		length      = str.length();
    bool	done        = false;

    if (length == 1)
    {
        result = 1;
    }

    else if (length == 2)
    {
        QString	temp = ConvertChar(str[0].toLatin1(), str[1].toLatin1());
        result = temp.length();
    }

    else
    {
        while (!done)
        {
            QString temp;

            qInfo() << "Reduction: " << localStr;
            for (int index = 0; index < localStr.length() - 1 && !done; index++)
            {
                temp = ConvertChar(localStr[index].toLatin1(), localStr[index + 1].toLatin1());

                // remove chars
                localStr.remove(index, 2);

                // replace chars
                localStr.insert(index, temp);
                qInfo().noquote() << " --> " << localStr;

                // check if end criteria met
                done = IsDone(localStr);
            }

            qInfo() << " ";

            if (done)
            {
                result = localStr.length();
            }

            else
            {
                qInfo().noquote() << "Need another iteration";
            }
        }
    }

    return result;
}

QString StringReducer::ConvertChar(char first, char second)
{
    QString result;

    if (first == second)
    {
        result += first;
        result += second;
    }

    else
    {
        if ((first == 'a' && second == 'b') ||
            (first == 'b' && second == 'a'))
        {
            result = "c";
        }

        else if ((first == 'a' && second == 'c') ||
            (first == 'c' && second == 'a'))
        {
            result = "b";
        }

        else if ((first == 'b' && second == 'c') ||
            (first == 'c' && second == 'b'))
        {
            result = "a";
        }
    }

    return result;
}

bool StringReducer::IsDone(QString str)
{
    bool	done    = false;
    int		length  = str.length();

    if (length == 1)
    {
        done = true;
    }

    else
    {
        done                = true;
        char	checkchar   = str[0].toLatin1();

        for (int index = 1; index < length && done; index++)
        {
            done = (checkchar == str[index].toLatin1());
        }
    }

    return done;
}
