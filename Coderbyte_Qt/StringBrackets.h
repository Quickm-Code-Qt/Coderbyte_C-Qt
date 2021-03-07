#pragma once

#include <QObject>

class StringBrackets : public QObject
{
    Q_OBJECT

public:
    StringBrackets(QObject *parent = nullptr);
    ~StringBrackets();

    int RemoveBrackets(QString str);
};
