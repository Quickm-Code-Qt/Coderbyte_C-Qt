#pragma once

#include <QObject>

class StringReverse : public QObject
{
    Q_OBJECT

public:
    StringReverse(QObject *parent = nullptr);
    ~StringReverse();

    QString FirstReverse(QString str);
};
