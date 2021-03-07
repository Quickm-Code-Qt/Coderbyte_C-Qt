#include "StringQuestionMarks.h"

StringQuestionMarks::StringQuestionMarks(QObject *parent)
    : QObject(parent)
{
}

StringQuestionMarks::~StringQuestionMarks()
{
}


// Have the function QuestionsMarks(str) take the str QString parameter, which 
// will contain single digit numbers, letters, and question marks, and check 
// if there are exactly 3 question marks between every pair of two numbers 
// that add up to 10. If so, then your program should return the QString true, 
// otherwise it should return the QString false.If there aren't any two numbers 
// that add up to 10 in the QString, then your program should return false as well.

// For example : if str is "arrb6???4xxbl5???eee5" then your program should return 
// true because there are exactly 3 question marks between 6 and 4, and 3 question 
// marks between 5 and 5 at the end of the QString.
QString StringQuestionMarks::QuestionsMarks(QString str)
{
    QString			result      = "false";
    bool			pass        = false;
    int				firstPos    = -1;
    int				secondPos   = -1;
    unsigned int	index       = 0;

    while (index < str.length())
    {
        if (FindNumbersInString(str, index, firstPos, secondPos))
        {
            QString temp;

            temp = str[firstPos];
            int first = temp.toInt();

            temp = str[secondPos];
            int second = temp.toInt();

            // 2 integers must equal 10
            if ((first + second) == 10)
            {
                // There must be exactly 3 question marks between 2 integers
                pass = IsQuestionMarksExist(str, firstPos, secondPos);
            }

            index = secondPos + 1;
        }

        // No numbers found in QString
        else
        {
            pass = false;
            break;
        }
    }

    result = pass ? "true" : "false";

    return result;
}

bool StringQuestionMarks::FindNumbersInString(const QString str, const int start, 
                                              int & first, int & second)
{
    bool result = false;

    first  = -1;
    second = -1;

    if (start == str.length() - 1)
    {
        return false;
    }

    for (unsigned int index = start; index < str.length(); index++)
    {
        if (str[index].isDigit())
        {
            if (first == -1)
            {
                first = index;
            }

            else
            {
                second = index;
                break;
            }
        }
    }

    result = (first != -1 && second != -1);

    return result;
}

bool StringQuestionMarks::IsQuestionMarksExist(const QString str,
                                               const int start, const int end)
{
    bool result = false;

    int num1 = start + 1;
    int num2 = end;
    int count = 0;

    if (num2 - num1 >= 3)
    {
        for (int index = num1; index < num2; index++)
        {
            if (str[index] == '?')
            {
                count++;
            }
        }

        result = (count == 3);
    }

    return result;
}
