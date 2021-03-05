#pragma once

#include <QObject>

class StringWordLength : public QObject
{
    Q_OBJECT

public:
    StringWordLength(QObject *parent = nullptr);
    ~StringWordLength();

    QString LongestWord(QString sentence);

};
