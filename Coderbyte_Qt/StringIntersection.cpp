#include "StringIntersection.h"
#include <QTextStream>

StringIntersection::StringIntersection(QObject *parent)
    : QObject(parent)
{
}

StringIntersection::~StringIntersection()
{
}

// Have the function FindIntersection(strArr) read the array of strings stored 
// in strArr which will contain 2 elements: the first element will represent a 
// list of comma - separated numbers sorted in ascending order, the second 
// element will represent a second list of comma - separated numbers(also sorted).
// Your goal is to return a comma - separated string containing the numbers that 
// occur in elements of strArr in sorted order.If there is no intersection, 
// return the string false.

// For example : if strArr contains["1, 3, 4, 7, 13", "1, 2, 4, 13, 15"] the 
// output should return "1,4,13" because those numbers appear in both strings.
// The array given will not be empty, and each string inside the array will be 
// of numbers sorted in ascending order and may contain negative numbers.
QString StringIntersection::FindIntersection(QStringList strArr)
{
    QString result;

    QVector<int> first;
    QVector<int> second;

    // convert to vector of ints
    Tokenize(strArr[0], ',', first);
    Tokenize(strArr[1], ',', second);

    // check for matches
    QVector<int>  match;
    for (unsigned int i = 0; i < first.size(); i++)
    {
        for (unsigned int j = 0; j < second.size(); j++)
            if (first[i] == second[j])
            {
                match.push_back(first[i]);
            }
    }

    // convert matches to string
    QString ss;
    if (match.size() != 0)
    {
        for (int item : match)
        {
            ss += QString::number(item);
            if (item != match[match.size() - 1])
            {
                ss += ',';
            }
        }

        result = (!ss.isEmpty()) ? ss : "false";
    }

    else
    {
        result = "false";
    }

    return result;
}


void StringIntersection::Tokenize(QString str, const char delim, QVector<int>& out)
{
    // construct a stream from the string
    QStringList         tokens;
    int					value;

    tokens = str.split(delim, QString::SplitBehavior::SkipEmptyParts, Qt::CaseInsensitive);
    for each (QString item in tokens)
    {
        value = item.toInt();
        out.push_back(value);
    }


}
