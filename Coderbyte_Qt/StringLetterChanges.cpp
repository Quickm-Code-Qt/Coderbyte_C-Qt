#include "StringLetterChanges.h"

StringLetterChanges::StringLetterChanges(QObject *parent)
    : QObject(parent)
{
}

StringLetterChanges::~StringLetterChanges()
{
}

// Have the function LetterChanges(str) take the str parameter being passed and 
// modify it using the following algorithm. Replace every letter in the string 
// with the letter following it in the alphabet (ie. c becomes d, z becomes a). 
// Then capitalize every vowel in this new string (a, e, i, o, u) and finally 
// return this modified string.

QString StringLetterChanges::LetterChanges(QString str)
{
    QString result = str;

    // 1st increment ascii value, wrap z to a
    // 2nd capitalize vowels  // std::locale loc; std::toupper(str[i],loc);
    for (int i = 0; i < result.length(); ++i) {

        if (result[i] >= 'a' && result[i] < 'z') 
        {
            //int x = result[i].unicode();
            //QChar ch(x + 1);
            //result[i] = ch;

            result[i].unicode()++;
        }
        else if (result[i] == 'z') {
            result[i] = 'a';
        }

        // Convert vowel to upper case
        if (result[i] == 'a' || result[i] == 'e' || result[i] == 'i' ||
            result[i] == 'o' || result[i] == 'u') 
        {
            result[i] = result[i].toUpper();
        }
    }

    return result;
}

// Have the function LetterCapitalize(str) take the str parameter being passed 
// and capitalize the first letter of each word. Words will be separated by 
// only one space.

QString StringLetterChanges::LetterCapitalize(QString str)
{
    QString result = str;

    for (int index = 0; index < result.length(); index++) {
        if (index == 0 && result[index].isLower())
        {
            result[index] = result[index].toUpper();
        }

        if (index > 0 && result[index - 1] == ' ') {
            result[index] = result[index].toUpper();
        }
    }

    return result;
}
