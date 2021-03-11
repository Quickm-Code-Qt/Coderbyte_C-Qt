#include "TreeGraphs.h"
#include <QMultiMap>

TreeGraphs::TreeGraphs(QObject *parent)
    : QObject(parent)
{
}

TreeGraphs::~TreeGraphs()
{
}

// For this challenge you will determine if an array of integer pairs can 
// form a binary tree properly.

// The function TreeConstructor(strArr) has a string array parameter strArr, 
// which will contain pairs of integers in the following format: (i1,i2), 
// where i1 represents a child node in a tree and the second integer i2 signifies 
// that it is the parent of i1. 

// For example: if strArr is ["(1,2)", "(2,4)", "(7,2)"] which you can see forms 
// a proper binary tree. Your program should, in this case, return the string true 
// because a valid binary tree can be formed. If a proper binary tree cannot be 
// formed with the integer pairs, then return the string false. All of the integers 
// within the tree will be unique, which means there can only be one node in the 
// tree with the given integer value.

QString TreeGraphs::TreeConstructor(QStringList strArr)
{
    bool					    validTree = true;
    QString					    result;
    QVector<QString>			input = strArr.toVector();
    QVector<QPair<int, int>>	data;
    QMultiMap<int, int>		    parents;
    QMap<int, int>              childCount;
    int						    root;

    data = ParseInput(input);

    for (QPair<int, int> item : data)
    {
        // parents[item.first] = item.second;
        parents.insert(item.first, item.second);
        childCount[item.second]++;
    }

    // find root
    for (auto item : data)
    {
        QMap<int, int>::iterator iter;

        iter = parents.find(item.second);
        if (iter == parents.end())
        {
            root = item.second;
        }
    }

    validTree = (root != 0);

    // check for > 2 children
    for (auto item : childCount)
    {
        if (item > 2)
        {
            validTree = false;
        }
    }

    // check for child with multiple parents

    QList<int>      values;
    for (auto item : parents)
    {
        values = parents.values(item);

        if (values.count() > 1)
        {
            validTree = false;
            break;
        }

        values.clear();
    }

    result = (validTree) ? "true" : "false";

    return result;
}

QVector<QPair<int, int>> TreeGraphs::ParseInput(QVector<QString> input)
{
    QVector<QPair<int, int>>	data;

    // parse input into data vector
    for (QString str : input)
    {
        int                 num1, num2;
        QPair<int, int>     temp;

        ParseInputString(str, num1, num2);
        temp = qMakePair(num1, num2);
        data.push_back(temp);
    }

    return data;
}

void TreeGraphs::ParseInputString(QString str, int & num1, int & num2)
{
    // assume correct structure
    // find comma -> substr-> trim '('
    // substr rest of str -> trim ')'

    int     pos;
    QString delimiter = ",";
    QString temp;

    // extract first number
    pos = str.indexOf(delimiter);
    if (pos != -1)
    {
        // remove ( char
        temp = str.mid(1, 1);
        num1 = temp.toInt();
    }

    // extract 2nd number
    temp = str.mid(pos + 1, 1);
    num2 = temp.toInt();

}
