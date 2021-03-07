#pragma once

#include <QObject>

class MathExponentTwo : public QObject
{
    Q_OBJECT

public:
    MathExponentTwo(QObject *parent = nullptr);
    ~MathExponentTwo();

    QString powersofTwo(int num);
};
