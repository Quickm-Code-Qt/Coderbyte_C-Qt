#include "StringPalindrome.h"

StringPalindrome::StringPalindrome(QObject *parent)
    : QObject(parent)
{
}

StringPalindrome::~StringPalindrome()
{
}

// The function Palindrome(str) has a string parameter,  return the string true
// if the parameter is a palindrome otherwise return the string false.  A 
// palindrome is the same forward as it is backwards. 

// For example : "racecar" is also "racecar" backwards. Punctuation and numbers 
// will not be part of the string.
QString StringPalindrome::Palindrome(QString str)
{
    QString	    result;
    QString     local;
    bool	    isPalindrome = false;

    // copy valid chars and resize QString
    auto it = std::copy_if(str.begin(), str.end(), std::back_inserter(local), [] (QChar c)
    {
        return !c.isSpace();
    });

    // Create backwards QString
    QString  backwards(local);
    std::reverse(backwards.begin(), backwards.end());

    result = (local.compare(backwards) == 0) ? "true" : "false";


    return result;
}
