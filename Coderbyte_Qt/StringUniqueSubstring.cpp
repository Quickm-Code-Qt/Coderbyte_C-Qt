#include "StringUniqueSubstring.h"
#include <QMap>

StringUniqueSubstring::StringUniqueSubstring(QObject *parent)
    : QObject(parent)
{
}

StringUniqueSubstring::~StringUniqueSubstring()
{
}

// For this challenge you will be searching a string for a particular substring.
// have the function KUniqueCharacters(str) take the str parameter being passed 
// and find the longest substring that contains k unique characters, where k will 
// be the first character from the string. The substring will start from the second 
// position in the string because the first character will be the integer k. 

// For example: if str is "2aabbacbaa" there are several substrings that all contain 
// 2 unique characters, namely: ["aabba", "ac", "cb", "ba"], but your program should 
// return "aabba" because it is the longest substring. If there are multiple longest 
// substrings, then return the first substring encountered with the longest length. 
// k will range from 1 to 6.
QString StringUniqueSubstring::KUniqueCharacters(QString str)
{
    QString				result;
    QString				localStr        = str.mid(1, str.length() - 1);
    int					uniqueLength = str[0].digitValue();
    bool				done            = false;
    int					substrLength    = localStr.length();
    QVector<QString>    substrings;

    if (uniqueLength > str.length() || uniqueLength == -1)
    {
        result = "Error: unique length is invalid";
        done = true;
    }

    while (!done)
    {
        int		uniqueCount = 0;

        substrings = CreateSubstrings(localStr, substrLength);
        if (substrings.size() == 0)
        {
            continue;
        }

        for (QString s : substrings) {
            uniqueCount = ComputeUniqueChars(s);
            if (uniqueCount == uniqueLength && s.length() > result.length())
            {
                result = s;
                done = true;
            }
        }

        substrings.clear();
        substrLength--;
    }


    return result;
}

int StringUniqueSubstring::ComputeUniqueChars(QString str)
{
    int count = 1;
    QMap<QChar, int> charCount;

    for (QChar c : str)
    {
        charCount[c]++;
    }

    count = charCount.size();

    return count;
}

QVector<QString> StringUniqueSubstring::CreateSubstrings(QString str, int length)
{
    QVector<QString>	substrings;
    int				    strLength   = str.length();

    if (length == strLength)
    {
        substrings.push_back(str);
    }

    else if (length < strLength)
    {
        QString substr;

        for (int index = 0; index + length <= strLength; index++)
        {
            substr = str.mid(index, length);
            substrings.push_back(substr);
        }
    }

    return substrings;
}

