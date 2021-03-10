#pragma once

#include <QObject>

class StringReducer : public QObject
{
    Q_OBJECT

public:
    StringReducer(QObject *parent = nullptr);
    ~StringReducer();

    int     StringReduction(QString str);

 protected:
    QString ConvertChar(char first, char second);
    bool	IsDone(QString str);

};
