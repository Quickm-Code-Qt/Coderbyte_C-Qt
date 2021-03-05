#include "StringWordLength.h"

StringWordLength::StringWordLength(QObject *parent)
    : QObject(parent)
{
}

StringWordLength::~StringWordLength()
{
}

// Have the function LongestWord(sen) take the sen parameter being passed and 
// return the largest word in the string.If there are two or more words that 
// are the same length, return the first word from the string with that length.
// Ignore punctuation and assume sen will not be empty.

QString StringWordLength::LongestWord(QString sentence)
{
    QString			longest = "";
    char			separator = ' ';
    QString			substring = "";
    int             prev_pos = 0, pos = 0;

    if (sentence.indexOf(separator, pos) == -1)
    {
        longest = sentence;
    }

    else
    {
        while ((pos = sentence.indexOf(separator, pos)) != -1)
        {
            // get substring
            substring = sentence.mid(prev_pos, pos - prev_pos);
            for (size_t i = 0; i < substring.length(); ++i)
            {
                // remove punctuation
                if (substring[i].isPunct())
                {
                    substring.remove(i--, 1);
                }
            }

            // check for longest word
            if (substring.length() > longest.length())
            {
                longest = substring;
            }

            prev_pos = ++pos;
        }

        substring = sentence.mid(prev_pos, pos - prev_pos);
        for (size_t i = 0; i < substring.length(); ++i)
        {
            if (substring[i].isPunct()) substring.remove(i--, 1);
        }
        if (substring.length() > longest.length())
        {
            longest = substring;
        }
    }

    return longest;
}
