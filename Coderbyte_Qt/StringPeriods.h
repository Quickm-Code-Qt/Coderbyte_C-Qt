#pragma once

#include <QObject>

class StringPeriod : public QObject
{
    Q_OBJECT

public:
    StringPeriod(QObject *parent = nullptr);
    ~StringPeriod();

    QString StringPeriods(QString str);

    protected:
    int CheckForMultipleSubstrings(QString sub, QString str);

};
