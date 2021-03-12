#pragma once

#include <QObject>

class MathKaprekar : public QObject
{
    Q_OBJECT

public:
    MathKaprekar(QObject *parent = nullptr);
    ~MathKaprekar();

    int KaprekarsConstant(int num);

protected:
    int ascendInt(int num);
    int descendInt(int num);

private:
    int  adjustInt(int num, bool descend);

};
