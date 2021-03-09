#pragma once

#include <QObject>

class StringNumberEncoder : public QObject
{
    Q_OBJECT

public:
    StringNumberEncoder(QObject *parent = nullptr);
    ~StringNumberEncoder();

    QString NumberEncoding(QString str);
protected:
    QMap<char, int>	CreateAlphabetMap();

};
