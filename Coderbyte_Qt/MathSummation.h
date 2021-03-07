#pragma once

#include <QObject>

class MathSummation : public QObject
{
    Q_OBJECT

public:
    MathSummation(QObject *parent= nullptr);
    ~MathSummation();

    int SimpleAdding(int num);
};
