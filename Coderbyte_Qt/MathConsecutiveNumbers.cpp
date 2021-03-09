#include "MathConsecutiveNumbers.h"

MathConsecutiveNumbers::MathConsecutiveNumbers(QObject *parent)
    : QObject(parent)
{
}

MathConsecutiveNumbers::~MathConsecutiveNumbers()
{
}

// For this challenge you will determine how to order an array of numbers 
// consecutively.

// The function Consecutive(arr) has an integer array paameter.  The function 
// returns the minimum number of integers needed to make the contents of arr 
// consecutive from the lowest number to the highest number. 

// For example: If arr contains [4, 8, 6] then the output should be 2 because 
// two numbers need to be added to the array (5 and 7) to make it a consecutive 
// array of numbers from 4 to 8. Negative numbers may be entered as parameters 
// and no array will have less than 2 elements. 
int MathConsecutiveNumbers::Consecutive(int arr[], unsigned int length)
{
    int				    missingCount = 0;
    std::vector<int>    stdContainer(arr, arr + length);
    QVector<int>        numbers = QVector<int>::fromStdVector(stdContainer);

    qSort(numbers);

    for (int index = 0; index < length - 1; index++)
    {
        int addCount = 0;
        while (numbers[index + 1] != numbers[index] + 1 + addCount)
        {
            addCount++;
        }

        missingCount += addCount;
    }

    return missingCount;
}
