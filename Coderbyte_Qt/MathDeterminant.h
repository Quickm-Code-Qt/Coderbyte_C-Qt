#pragma once

#include <QObject>

class MathDeterminant : public QObject
{
    Q_OBJECT

public:
    MathDeterminant(QObject *parent = nullptr);
    ~MathDeterminant();

    int MatrixDeterminant(QStringList   strArr);

    protected:
    bool IsSquareMatrix(QVector<QVector<int>> & matrix);
    void ParseMatrix(QStringList strArr, int size, QVector<QVector<int>> & matrix);
    int  ComputeDeterminant(QVector < QVector<int>> & matrix);

};
