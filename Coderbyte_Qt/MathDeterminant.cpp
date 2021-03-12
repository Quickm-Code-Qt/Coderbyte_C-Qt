#include "MathDeterminant.h"
#include <QDebug>

MathDeterminant::MathDeterminant(QObject *parent)
    : QObject(parent)
{
}

MathDeterminant::~MathDeterminant()
{
}

// Have the function MatrixDeterminant(strArr) read strArr which will be an 
// array of integers represented as strings.Within the array there will also 
// be "<>" elements which represent break points.The array will make up a 
// matrix where the(number of break points + 1) represents the number of 
// rows.Here is an example of how strArr may look : ["1", "2", "<>", "3", "4"].
//
// The contents of this array are row1 = [1 2] and row2 = [3 4]. Your program 
// should take the given array of elements, create the proper matrix, and then 
// calculate the determinant. For the example above, your program should return -2. 
// If the matrix is not a square matrix, return -1. The maximum size of strArr
// will be a 6x6 matrix.The determinant will always be an integer.
int MathDeterminant::MatrixDeterminant(QStringList strArr)
{
    int					    value = -1;
    QVector<QVector<int>>   matrix;

    ParseMatrix(strArr, strArr.size(), matrix);


    if (IsSquareMatrix(matrix))
    {
        qInfo() << "Matrix is square";

        value = ComputeDeterminant(matrix);
    }

    else
    {
        qInfo() << "Matrix is not square";
    }

    return value;
}

bool MathDeterminant::IsSquareMatrix(QVector<QVector<int>>& matrix)
{
    bool valid = true;

    // checking if input matrix is square
    for (unsigned int row = 0; row < matrix.size(); row++)
    {
        if (matrix[row].size() != matrix.size())
        {
            valid = false;
            break;
        }
    }

    return valid;
}

void MathDeterminant::ParseMatrix(QStringList strArr, int size, QVector<QVector<int>>& matrix)
{
    QVector<int> temp;

    // traversing the input array to build our matrix
    for (auto item : strArr)
    {
        // condition to check for breakpoints
        if (item == "<>")
        {
            matrix.push_back(temp);
            temp.clear();
        }
        else
        {
            // converting to int
            int value = item.toInt();

            // adding to our row
            temp.push_back(value);
        }
    }

    // adding last row
    matrix.push_back(temp);
    temp.clear();

}

int MathDeterminant::ComputeDeterminant(QVector<QVector<int>>& matrix)
{
    int value = 0;
    if (matrix.size() == 1)
    {
        value = matrix[0][0];
    }
    // check for 2-by-2 matrix perform det calculation
    else if (matrix.size() == 2)
    {
        value = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
    }

    // otherwise determine cofactor, submatrix and recursively compute determinant
    else
    {
        int cofactor = 0;
        // iterate across first row to set cofactor
        for (unsigned int p = 0; p < matrix[0].size(); p++)
        {
            // create submatrix
            QVector<QVector<int>> subMatrix;
            for (unsigned int i = 1; i < matrix.size(); i++)
            {
                // iteration will start from row one cancelling the first row values
                QVector<int> tempRow;
                for (unsigned int j = 0; j < matrix[i].size(); j++)
                {
                    // iteration will pass all cells of the i row excluding the j 
                    //value that match p column
                    if (j != p)
                    {
                        tempRow.push_back(matrix[i][j]);//add current cell to TempRow 
                    }
                }

                // Adding each row to submatrix
                if (tempRow.size() > 0)
                {
                    subMatrix.push_back(tempRow);
                }
            }

            // recursively calculate the determinant value
            cofactor = matrix[0][p];
            value += static_cast<int>(pow(-1, p)) * cofactor * ComputeDeterminant(subMatrix);
        }
    }

    return value;
}
