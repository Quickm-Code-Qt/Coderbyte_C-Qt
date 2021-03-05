#include "TestChallenges.h"
#include <QDebug>
#include <vector>

#include "AlphabetSorter.h"
#include "MathSequence.h"
#include "NumberCheck.h"
#include "MathFibonacci.h"
#include "StringIntersection.h"
#include "MathFactorial.h"


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


