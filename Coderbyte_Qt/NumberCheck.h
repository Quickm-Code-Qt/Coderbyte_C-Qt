#pragma once

#include <QObject>

class NumberCheck : public QObject
{
    Q_OBJECT

public:
    NumberCheck(QObject *parent = nullptr);
    ~NumberCheck();

    QString checkNums(int num1, int num2);


};
