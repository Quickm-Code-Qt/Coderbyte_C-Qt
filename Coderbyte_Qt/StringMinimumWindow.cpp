#include "StringMinimumWindow.h"
#include <QMap>

StringMinimumWindow::StringMinimumWindow(QObject *parent)
    : QObject(parent)
{
}

StringMinimumWindow::~StringMinimumWindow()
{
}

// Have the function MinWindowSubstring(strArr) take the array of strings stored
// in strArr, which will contain only two strings, the first parameter being the 
// string N and the second parameter being a string K of some characters, and your 
// goal is to determine the smallest substring of N that contains all the characters 
// in K. 
//
// For example: if strArr is ["aaabaaddae", "aed"] then the smallest substring of N 
// that contains the characters a, e, and d is "dae" located at the end of the string. 
// So for this example your program should return the string dae.

// Another example: if strArr is ["aabdccdbcacd", "aad"] then the smallest substring 
// of N that contains all of the characters in K is "aabd" which is located at the 
// beginning of the string. Both parameters will be strings ranging in length from 
// 1 to 50 characters and all of K's characters will exist somewhere in the string N. 
// Both strings will only contains lowercase alphabetic characters.

// Examples
// Input: {"ahffaksfajeeubsne", "jefaa"}
// Output: aksfaje

// Input: {"aaffhkksemckelloe", "fhea"}
// Output: affhkkse

QString StringMinimumWindow::MinWindowSubstring(QStringList strArr)
{
    QString             result;
    QString             text    = strArr[0];
    QString             pattern = strArr[1];

    QMap<char, int>	    countMap    = CreateCountMap(pattern);
    QVector<QString>	windows     = ExtractWindows(text, pattern.length());

    for (const QString window : windows)
    {
        if (IsValidWindow(window, countMap))
        {
            if (result.isEmpty())
            {
                result = window;
            }
            else if (window.length() < result.length())
            {
                result = window;
            }
        }
    }

    return result;
}

QMap<char, int> StringMinimumWindow::CreateCountMap(const QString s)
{
    QMap<char, int> countMap;

    for (QChar ch : s) 
    {
        char c = ch.toLatin1();
        countMap[c]++;
    }

    return countMap;
}

QVector<QString> StringMinimumWindow::ExtractWindows(const QString str, int length)
{
    QVector<QString> windows;
    int strLength = str.length();


    for (int start = 0; start < strLength; start++)
    {
        for (int end = start + length; end < strLength + 1; end++)
        {
            windows.push_back(str.mid(start, end - start));
        }
    }

    return windows;
}

bool StringMinimumWindow::IsValidWindow(const QString window, QMap<char, int> patternMap)
{
    bool			        isValid = true;
    const QMap<char, int>	windowMap = CreateCountMap(window);

    for (QMap<char, int>::iterator it = patternMap.begin(); it != patternMap.end(); ++it)
    {
        const auto key = it.key();
        const auto val = it.value();

        if (windowMap.find(key) == windowMap.end() || windowMap.value(key) < val)
        {
            isValid = false;
        }
    }

    return isValid;
}
