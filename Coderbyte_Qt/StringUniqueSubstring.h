#pragma once

#include <QObject>

class StringUniqueSubstring : public QObject
{
    Q_OBJECT

public:
    StringUniqueSubstring(QObject *parent = nullptr);
    ~StringUniqueSubstring();

    QString					KUniqueCharacters(QString str);

    protected:
    int						ComputeUniqueChars(QString str);
    QVector<QString>        CreateSubstrings(QString str, int length);
};
