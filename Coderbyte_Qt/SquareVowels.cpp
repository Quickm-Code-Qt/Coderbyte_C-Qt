#include "SquareVowels.h"

SquareVowels::SquareVowels(QObject *parent)
    : QObject(parent)
{
}

SquareVowels::~SquareVowels()
{
}
//Have the function VowelSquare(strArr) take the strArr parameter being passed which
//will be a 2D matrix of some arbitrary size filled with letters from the alphabet
//and determine if a 2x2 square composed entirely of vowels exists in the matrix.For
//example: strArr is["abcd", "eikr", "oufj"] then this matrix looks like the following :
//a b c d
//e i k r
//o u f j
//Within this matrix there is a 2x2 square of vowels starting in the second row and first
//column, namely, ei, ou.If a 2x2 square of vowels is found your program should return
//the top - left position(row - column) of the square, so for this example your program should
//return 1 - 0. If no 2x2 square of vowels exists, then return the string not found.If there
//are multiple squares of vowels, return the one that is at the most top - left position in
//the whole matrix.The input matrix will at least be of size 2x2.

QString SquareVowels::VowelSquare(QStringList strArr, int length)
{
    QString          result = "not found";
    //stringstream    ss;
    bool            found = false;

    for (int row = 0; row < length && !found; row++)
    {
        int colLength = strArr[row].length();
        for (int col = 0; col < colLength - 1 && !found; col++)
        {
            if (IsVowel(strArr[row][col]) && IsVowel(strArr[row][col + 1]) &&
                IsVowel(strArr[row + 1][col]) && IsVowel(strArr[row + 1][col + 1]))
            {
                result = QString("%1-%2").arg(QString::number(row), QString::number(col));
                //ss << row << "-" << col;
                //result = ss.str();
                found = true;
            }
        }
    }
    return result;
}

bool SquareVowels::IsVowel(const QChar c)
{
    bool    isValid = false;

    switch (c.toLatin1())
    {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'y':
            isValid = true;
            break;
        default:
            break;
    }

    return isValid;
}

