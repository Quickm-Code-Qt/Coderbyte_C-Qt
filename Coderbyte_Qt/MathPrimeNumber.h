#pragma once

#include <QObject>

class MathPrimeNumber : public QObject
{
    Q_OBJECT

public:
    MathPrimeNumber(QObject *parent = nullptr);
    ~MathPrimeNumber();

    int             PrimeMover(unsigned int num);

 protected:
    QVector<int>	PrefillPrimeVector();
    bool			IsPrimeNumber(int n, const QVector<int> & primes);

};
