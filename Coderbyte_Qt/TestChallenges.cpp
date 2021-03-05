#include "TestChallenges.h"
#include <QDebug>
#include <vector>

#include "AlphabetSorter.h"
#include "MathSequence.h"
#include "NumberCheck.h"
#include "MathFibonacci.h"


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


