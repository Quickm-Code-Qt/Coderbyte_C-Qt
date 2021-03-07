#pragma once

#include <QObject>

class StringSymbols : public QObject
{
    Q_OBJECT

public:
    StringSymbols(QObject *parent = nullptr);
    ~StringSymbols();

    QString SimpleSymbols(QString str);

};
