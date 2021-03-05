#include "TestChallenges.h"
#include <QDebug>

#include "AlphabetSorter.h"
TestChallenges::TestChallenges(QObject *parent)
    : QObject(parent)
{
}

TestChallenges::~TestChallenges()
{
}
void TestChallenges::Test_AlphabetSoup()
{
    QString text = "jgklsgtiowegtankvlae";
    AlphabetSorter alpha;

    qInfo() << "Alphabet Soup:";
    qInfo() << "Input:  " << text;
    qInfo() << "Output: " << alpha.AlphabetSoup(text);
    qInfo() << " ";

}

