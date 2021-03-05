#include "AlphabetSorter.h"

AlphabetSorter::AlphabetSorter(QObject *parent)
    : QObject(parent)
{
}

AlphabetSorter::~AlphabetSorter()
{
}

// Have the function AlphabetSoup(str) take the str string parameter being 
// passed and return the string with the letters in alphabetical order (ie. 
// hello becomes ehllo). Assume numbers and punctuation symbols will not 
// be included in the string.
QString AlphabetSorter::AlphabetSoup(QString str)
{
    QString result = str;

    std::sort(result.begin(), result.end());

    return result;
}