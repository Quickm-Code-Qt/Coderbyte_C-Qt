#pragma once

#include <QObject>

class MathSequence : public QObject
{
public:
    MathSequence(QObject *parent = nullptr);
    ~MathSequence();

    QString ArithGeo(int arr[], const int length);
protected:
    bool		isArithematicSequence(int arr[], const int length);
    bool		isGeometricSequence(int arr[], const int length);
};
