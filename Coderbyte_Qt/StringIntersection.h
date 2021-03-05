#pragma once

#include <QObject>

class StringIntersection : public QObject
{
    Q_OBJECT

public:
    StringIntersection(QObject *parent = nullptr);
    ~StringIntersection();

    QString FindIntersection(QStringList strArr);

protected:
    void Tokenize(QString  str, const char delim, QVector<int>& out);
};
