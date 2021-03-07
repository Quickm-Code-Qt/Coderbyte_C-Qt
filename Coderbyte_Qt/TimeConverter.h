#pragma once

#include <QObject>

class TimeConverter : public QObject
{
    Q_OBJECT

public:
    TimeConverter(QObject *parent = nullptr);
    ~TimeConverter();

    QString TimeConvert(int num);
};
