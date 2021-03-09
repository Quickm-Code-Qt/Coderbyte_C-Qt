#include "StringNumberEncoder.h"
#include <QMap>

StringNumberEncoder::StringNumberEncoder(QObject *parent)
    : QObject(parent)
{
}

StringNumberEncoder::~StringNumberEncoder()
{
}

// For this challenge you will encode a given string following a specific rule.
// The function NumberEncoding(str) with str parameter and encode the 
// message according to the following rule: encode every letter into its 
// corresponding numbered position in the alphabet. Symbols and spaces will also 
// be used in the input. 

// For example: if str is "af5c a#!" then your program should return 1653 1#!. 
QString         StringNumberEncoder::NumberEncoding(QString str)
{
    QString			result;
    QMap<char, int>	alphabet;

    alphabet = CreateAlphabetMap();

    for (QChar item : str)
    {
        // is a letter
        if (item.isLetter()) {
            result += QString::number(alphabet[item.toLatin1()]);
        }

        // not a letter
        else
        {
            result += item;
        }
    }


    return result;
}

QMap<char, int> StringNumberEncoder::CreateAlphabetMap()
{
    QMap<char, int>	alpha;
    int				value = 1;

    for (char key = 'a'; key <= 'z'; key++, value++)
    {
        alpha[key] = value;
    }
    return alpha;
}

