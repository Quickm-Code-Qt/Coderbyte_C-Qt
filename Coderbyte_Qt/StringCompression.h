#pragma once

#include <QObject>

class StringCompression : public QObject
{
    Q_OBJECT

public:
    StringCompression(QObject *parent = nullptr);
    ~StringCompression();

    QString		RunLength(QString str);


 protected:
    bool		IsRepeatingChar(QString str, int index, int & count);

};
