#include "TestChallenges.h"
#include <QDebug>
#include <vector>

// Easy Challenges
#include "AlphabetSorter.h"
#include "MathSequence.h"
#include "NumberCheck.h"
#include "MathFibonacci.h"
#include "StringIntersection.h"
#include "MathFactorial.h"
#include "StringReverse.h"
#include "StringLetterChanges.h"
#include "StringWordLength.h"
#include "StringPalindrome.h"
#include "MathExponentTwo.h"
#include "MathProduct.h"
#include "StringBrackets.h"
#include "StringQuestionMarks.h"
#include "MathSummation.h"
#include "StringSymbols.h"
#include "StringPeriods.h"
#include "TimeConverter.h"
#include "SquareVowels.h"
#include "UsernameValidation.h"
#include "MathMedianMovement.h"

// Medium Challenges
#include "MathConsecutiveNumbers.h"
#include "StringUniqueSubstring.h"
#include "StringNumberEncoder.h"
#include "MathPrimeNumber.h"

TestChallenges::TestChallenges(QObject *parent)
    : QObject(parent)
{
}

TestChallenges::~TestChallenges()
{
}

void TestChallenges::Test_PrintArray(int* arr, int length)
{
    std::vector<int>    stdContainer(arr, arr + length);
    QVector<int>        container = QVector<int>::fromStdVector(stdContainer);

    QDebug log = qInfo().noquote();
    log << "Array: " << "[";
    QString str;

    for (auto const& value : container)
    {
        str += QString::number(value);
        str += ",";
    }

    str.chop(1);
    log << str << "]";
}

void TestChallenges::Test_PrintArray(QStringList strArr)
{
    QDebug log = qInfo().noquote();
    log << "Array: " << "[";
    QString str;

    for (int index = 0; index < strArr.length(); index++)
    //for (auto value : strArr)
    {
        auto value = strArr[index];
        str += "[" + QString::number(index) + "]: ";
        str += value;
        str += ",";
    }

    str.chop(1);
    log << str << "]";
}



void TestChallenges::Test_AlphabetSoup()
{
    QString text = "jgklsgtiowegtankvlae";
    AlphabetSorter alpha;

    qInfo() << "Alphabet Soup:";
    qInfo().noquote() << "Input:  " << text;
    qInfo().noquote() << "Output: " << alpha.AlphabetSoup(text);
    qInfo() << " ";

}

void TestChallenges::Test_ArithGeo()
{
    int				arr[4] = {2,4,8,16};
    int				length = 4;
    MathSequence	sequence;

    qInfo() << "ArithGeo: ";
    Test_PrintArray(arr, length);
    qInfo().noquote() << "Result: " << sequence.ArithGeo(arr, length);
    qInfo() << " ";

}

void TestChallenges::Test_NumberCheck()
{
    NumberCheck  checker;

    int number1 = 23;
    int	number2 = 45;

    qInfo() << "Number Check:";
    qInfo() << "Input:  " << "Numbers: " << number1 << number2;
    qInfo().noquote() << "Output: " << checker.checkNums(number1, number2);

    number1 = 37;
    number2 = 25;
    qInfo() << "Input:  " << "Numbers: " << number1 << number2;
    qInfo().noquote() << "Output: " << checker.checkNums(number1, number2);

    number1 = 25;
    number2 = 25;
    qInfo() << "Input:  " << "Numbers: " << number1 << number2;
    qInfo().noquote() << "Output: " << checker.checkNums(number1, number2);
    qInfo() << " ";

}

void TestChallenges::Test_Fibonacci()
{
    MathFibonacci  checker;

    int num = 23;

    qInfo() << "Fibonacci Checker:";
    qInfo() << "Input:  " << num;
    qInfo().noquote() << "Output: " << checker.FibonacciChecker(num);

    num = 34;
    qInfo() << "Input:  " << num;
    qInfo().noquote() << "Output: " << checker.FibonacciChecker(num);

    num = 25;
    qInfo() << "Input:  " << num;
    qInfo().noquote() << "Output: " << checker.FibonacciChecker(num);
    qInfo() << " ";

}

void TestChallenges::Test_FindIntersection()
{
    StringIntersection   intersect;
    QStringList          list;

    QString     one = "3, 4, 7, 11, 21";
    QString     two = "4, 6, 7, 13, 21";

    list.append(one);
    list.append(two);

    qInfo() << "Find Intersection: ";
    Test_PrintArray(list);
    qInfo().noquote() << "Result: " << intersect.FindIntersection(list);
    qInfo() << " ";

}

void TestChallenges::Test_FirstFactorial()
{
    MathFactorial  factorial; 

    int num = 23;

    qInfo() << "First Factorial:";
    qInfo() << "Input:  " << num;
    qInfo().noquote() << "Output: " << factorial.FirstFactorial(num);

    num = 6;
    qInfo() << "Input:  " << num;
    qInfo().noquote() << "Output: " << factorial.FirstFactorial(num);

    num = 8;
    qInfo() << "Input:  " << num;
    qInfo().noquote() << "Output: " << factorial.FirstFactorial(num);
    qInfo() << " ";
}

void TestChallenges::Test_StringReverse()
{
    StringReverse reverse;
    QString text = "Hello World and Coders";

    qInfo() << "First Reverse:";
    qInfo().noquote() << "Input:  " << text;
    qInfo().noquote() << "Output: " << reverse.FirstReverse(text);
    qInfo() << " ";

}

void TestChallenges::Test_LetterChanges()
{
    StringLetterChanges  letterChanger;

    QString text = "coderbyte";

    qInfo() << "Letter Changes:";
    qInfo().noquote() << "Input:  " << text;
    qInfo().noquote() << "Output: " << letterChanger.LetterChanges(text);
    qInfo() << " ";
}

void TestChallenges::Test_LetterCapitalize()
{
    StringLetterChanges  letterChanger;

    QString text = "the fox is brown in color and very sly.";

    qInfo() << "Letter Changes:";
    qInfo().noquote() << "Input:  " << text;
    qInfo().noquote() << "Output: " << letterChanger.LetterCapitalize(text);
    qInfo() << " ";

}

void TestChallenges::Test_LongestWord()
{
    StringWordLength  lengthFinder;;

    QString text = "The fox wouldn't lazy in the forest.";

    qInfo() << "Longest Word:";
    qInfo().noquote() << "Input:  " << text;
    qInfo().noquote() << "Output: " << lengthFinder.LongestWord(text);
    qInfo() << " ";

}

void TestChallenges::Test_Palindrome()
{
    StringPalindrome    palin;
    QString             text = "race car";

    qInfo() << "Palindrome:";
    qInfo().noquote() << "Input:  " << text;
    qInfo().noquote() << "Output: " << palin.Palindrome(text);

    text = "r a s ecar";
    qInfo().noquote() << "Input:  " << text;
    qInfo().noquote() << "Output: " << palin.Palindrome(text);
    qInfo() << " ";
}

void TestChallenges::Test_PowersOfTwo()
{
    MathExponentTwo  exp;

    int num = 23;

    qInfo() << "Powers of Two:";
    qInfo() << "Input:  " << num;
    qInfo().noquote() << "Output: " << exp.powersofTwo(num);

    num = 4;
    qInfo() << "Input:  " << num;
    qInfo().noquote() << "Output: " << exp.powersofTwo(num);

    num = 56;
    qInfo() << "Input:  " << num;
    qInfo().noquote() << "Output: " << exp.powersofTwo(num);
    qInfo() << " ";
}

void TestChallenges::Test_ProductDigits()
{
    MathProduct   product;
    int           num = 6;

    qInfo() << "Product Digits:";
    qInfo() << "Input:  " << num;
    qInfo().noquote() << "Output: " << product.ProductDigits(num);

    num = 23;
    qInfo() << "Input:  " << num;
    qInfo().noquote() << "Output: " << product.ProductDigits(num);

    num = 90;
    qInfo() << "Input:  " << num;
    qInfo().noquote() << "Output: " << product.ProductDigits(num);
    qInfo() << " ";
}

void TestChallenges::Test_OtherProducts()
{
    MathProduct		product;
    int				arr[5] = {1,2,3,4,5};
    int             length = 5;

    qInfo() << "Other Products: ";
    Test_PrintArray(arr, length);
    qInfo().noquote() << "Result: " << product.OtherProducts(arr, length);
    qInfo() << " ";


}

void TestChallenges::Test_RemoveBrackets()
{
    StringBrackets    bracket;
    qInfo() << "Remove Brackets:";

    QString           text      = "(()))";
    qInfo().noquote() << "Input:  " << text;
    qInfo().noquote() << "Output: " << bracket.RemoveBrackets(text);    
    
    text = ")(()";
    qInfo().noquote() << "Input:  " << text;
    qInfo().noquote() << "Output: " << bracket.RemoveBrackets(text);
    qInfo() << " ";
}

void TestChallenges::Test_QuestionMarks()
{
    StringQuestionMarks    questionMark;
    qInfo() << "Question Marks:";

    QString           text = "arrb6???4xxbl5???eee5";
    qInfo().noquote() << "Input:  " << text;
    qInfo().noquote() << "Output: " << questionMark.QuestionsMarks(text);

    text = "arrb6???4xxbl5??eee5";
    qInfo().noquote() << "Input:  " << text;
    qInfo().noquote() << "Output: " << questionMark.QuestionsMarks(text);
    qInfo() << " ";

}

void TestChallenges::Test_SimpleAdding()
{
    MathSummation   sum;
    qInfo() << "Simple Adding:";

    int             num = 6;

    qInfo() << "Input:  " << num;
    qInfo().noquote() << "Output: " << sum.SimpleAdding(num);

    num = 23;
    qInfo() << "Input:  " << num;
    qInfo().noquote() << "Output: " << sum.SimpleAdding(num);
    qInfo() << " ";


}

void TestChallenges::Test_SimpleSymbols()
{
    StringSymbols   symbol;
    qInfo() << "Simple Symbols:";

    QString           text = "++d+===+c++==a";
    qInfo().noquote() << "Input:  " << text;
    qInfo().noquote() << "Output: " << symbol.SimpleSymbols(text);

    text = "++d+===+c++==";
    qInfo().noquote() << "Input:  " << text;
    qInfo().noquote() << "Output: " << symbol.SimpleSymbols(text);
    qInfo() << " ";


}

void TestChallenges::Test_StringPeriods()
{   
    StringPeriod    period;
    qInfo() << "String Periods:";

    QString           text = "abababababab";
    qInfo().noquote() << "Input:  " << text;
    qInfo().noquote() << "Output: " << period.StringPeriods(text);

    text = "abcababcababcab";
    qInfo().noquote() << "Input:  " << text;
    qInfo().noquote() << "Output: " << period.StringPeriods(text);
    qInfo() << " ";
}

void TestChallenges::Test_TimeConverter()
{
    TimeConverter   converter;
    qInfo() << "Time Converter:";

    int             num = 67;
    qInfo() << "Input:  " << num;
    qInfo().noquote() << "Output: " << converter.TimeConvert(num);

    num = 100;
    qInfo() << "Input:  " << num;
    qInfo().noquote() << "Output: " << converter.TimeConvert(num);
    qInfo() << " ";


}

void TestChallenges::Test_VowelSquares()
{
    SquareVowels   vowels;
    qInfo() << "Vowel Square:";

    QStringList    rows = {"abcd", "eikr", "oufj"};

    Test_PrintArray(rows);
    qInfo().noquote() << "Result: " << vowels.VowelSquare(rows, rows.length());
    qInfo() << " ";

}

void TestChallenges::Test_UsernameValidation()
{
    UsernameValidation validator;
    qInfo() << "Username Validation:";

    QString  username = "t9_fjrjkgljoirg8945jgg";
    qInfo().noquote() << "Input:  " << username;
    qInfo().noquote() << "Output: " << validator.CodelandUsernameValidation(username);

    username = "t9_fjrjkgljoirg8945jgg_";
    qInfo().noquote() << "Input:  " << username;
    qInfo().noquote() << "Output: " << validator.CodelandUsernameValidation(username);
    qInfo() << " ";



}

void TestChallenges::Test_MovingMedian()
{
    MathMedianMovement  median;
    qInfo() << "Moving Median:";

    int				arr[9] = {3, 1, 3, 5, 10, 6, 4, 3, 1};
    int             length = 9;

    Test_PrintArray(arr, length);
    qInfo().noquote() << "Result: " << median.MovingMedian(arr, length);
    qInfo() << " ";

}

void TestChallenges::Test_ConsecutiveNumbers()
{
    MathConsecutiveNumbers      consecutive;
    qInfo() << "Consecutive Numbers:";

    int				arr[] = {4, 8, 6};
    int             length = 3;

    Test_PrintArray(arr, length);
    qInfo().noquote() << "Result: " << consecutive.Consecutive(arr, length);
    qInfo() << " ";

    int				arr2[] = {4, 8, 6, 9, 11};
                    length = 5;

    Test_PrintArray(arr2, length);
    qInfo().noquote() << "Result: " << consecutive.Consecutive(arr2, length);
    qInfo() << " ";
}

void TestChallenges::Test_KUniqueCharacters()
{
    StringUniqueSubstring unique;
    qInfo() << "K Unique Characters:";

    QString  text = "2aabbacbaa";
    qInfo().noquote() << "Input:  " << text;
    qInfo().noquote() << "Output: " << unique.KUniqueCharacters(text);

    text = "zaabbacbaa";
    qInfo().noquote() << "Input:  " << text;
    qInfo().noquote() << "Output: " << unique.KUniqueCharacters(text);
    qInfo() << " ";

}

void TestChallenges::Test_NumberEncoder()
{
    StringNumberEncoder encoder;
    qInfo() << "Number Encoder:";

    QString  text = "af5c a#!";
    qInfo().noquote() << "Input:  " << text;
    qInfo().noquote() << "Output: " << encoder.NumberEncoding(text);

    text = "af5c a#!p";
    qInfo().noquote() << "Input:  " << text;
    qInfo().noquote() << "Output: " << encoder.NumberEncoding(text);
    qInfo() << " ";
}

void TestChallenges::Test_PrimeMover()
{
    MathPrimeNumber  primer;
    qInfo() << "Prime Mover:";

    int             num = 16;
    qInfo() << "Input:  " << num;
    qInfo().noquote() << "Output: " << primer.PrimeMover(num);

                    num = 5;
    qInfo() << "Input:  " << num;
    qInfo().noquote() << "Output: " << primer.PrimeMover(num);
    qInfo() << " ";

}


