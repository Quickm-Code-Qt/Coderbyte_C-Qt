#pragma once

#include <QObject>

class MathProduct : public QObject
{
    Q_OBJECT

public:
    MathProduct(QObject *parent = nullptr);
    ~MathProduct();

    int			ProductDigits(int num);
    QString     OtherProducts(int arr[], int length);
 protected:
    int computeProduct(int arr[], int length, int index);

};
