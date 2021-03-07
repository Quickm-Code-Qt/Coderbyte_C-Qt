#include <QtCore/QCoreApplication>
#include "TestChallenges.h"
int main(int argc, char *argv[])
{
    /*QCoreApplication a(argc, argv);

    return a.exec();*/

    TestChallenges tc;

    // Easy Challenges
    tc.Test_AlphabetSoup();
    tc.Test_ArithGeo();
    tc.Test_NumberCheck();
    tc.Test_Fibonacci();
    tc.Test_FindIntersection();
    tc.Test_FirstFactorial();
    tc.Test_StringReverse();
    tc.Test_LetterChanges();
    tc.Test_LetterCapitalize();
    tc.Test_LongestWord();
    tc.Test_Palindrome();

    // Medium Challenges


    // Hard Challenges

    return 0;
}
 