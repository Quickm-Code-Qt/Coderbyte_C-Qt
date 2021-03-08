#include "MathMedianMovement.h"

MathMedianMovement::MathMedianMovement(QObject *parent)
    : QObject(parent)
{
}

MathMedianMovement::~MathMedianMovement()
{
}

// Have the function MovingMedian(arr) read the array of numbers stored in arr 
// which will contain a sliding window size, N, as the first element in the array 
// and the rest will be a list of numbers. Your program should return the Moving 
// Median for each element based on the element and its N-1 predecessors, where N 
// is the sliding window size. The final output should be a string with the moving 
// median corresponding to each entry in the original array separated by commas.

// Note that for the first few elements(until the window size is reached), the median 
// is computed on a smaller number of entries.For example : if arr is [3, 1, 3, 5, 10, 
// 6, 4, 3, 1] then your program should output "1,2,3,5,6,6,4,3".

QString MathMedianMovement::MovingMedian(int arr[], const int length)
{
    QString			result;
    QVector<int>	nums;
    unsigned int	windowSize = arr[0];
    int				median = 0;

    for (int i = 1; i < length; i++)
    {
        nums.push_back(arr[i]);
        if (nums.size() > windowSize)
        {
            nums.erase(nums.begin(), nums.begin() + 1);
        }

        median = CalculateMedian(nums);
        result += QString::number(median) + ",";
    }

    result.chop(1);

    return result;
}

int MathMedianMovement::CalculateMedian(QVector<int> values)
{
    int median = 0;
    int half = values.size() / 2;

    qSort(values);

    median = (values.size() % 2 == 0) ? (values[half - 1] + values[half]) / 2
        : values[half];

    return median;
}
