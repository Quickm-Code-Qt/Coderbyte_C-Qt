#pragma once

#include <QObject>

class MathMedianMovement : public QObject
{
    Q_OBJECT

public:
    MathMedianMovement(QObject *parent = nullptr);
    ~MathMedianMovement();

    QString MovingMedian(int arr[], const int length);
 protected:
    int			CalculateMedian(QVector<int> values);

};
