#include "MathPrimeNumber.h"

MathPrimeNumber::MathPrimeNumber(QObject *parent)
    : QObject(parent)
{
}

MathPrimeNumber::~MathPrimeNumber()
{
}

// For this challenge you will be returning a certain prime number.
// The function PrimeMover(num) returns the numth prime number. 
// The range will be from 1 to 10^4. 
// For example: if num is 16 the output should be 53 as 53 is 
// the 16th prime number.

int MathPrimeNumber::PrimeMover(unsigned int num)
{
    int				primeValue  = 1;
    bool			found       = false;
    QVector<int>	primes      = PrefillPrimeVector();
    int				index       = primes.size();

    if (primes.size() >= num)
    {
        primeValue = primes[num - 1];
        found = true;
    }

    while (primes.size() < num)
    {
        bool	isPrime = false;

        index++;
        isPrime = IsPrimeNumber(index, primes);
        if (isPrime)
        {
            primes.push_back(index);
            if (primes.size() == num)
            {
                found = true;
                break;
            }
        }
    }

    if (found)
    {
        primeValue = primes[num - 1];
    }

    return primeValue;
}

QVector<int> MathPrimeNumber::PrefillPrimeVector()
{
    QVector<int>		primes;

    primes.push_back(2);
    primes.push_back(3);
    primes.push_back(5);
    primes.push_back(7);
    primes.push_back(11);
    primes.push_back(13);
    primes.push_back(17);
    primes.push_back(19);

    return primes;
}

bool MathPrimeNumber::IsPrimeNumber(int num, const QVector<int> & primes)
{
    bool	result = true;

    for (int index : primes)
    {
        if (num % index == 0)
        {
            result = false;
            break;
        }
    }

    return result;
}
