#pragma once

#include <QObject>

class StringLetterChanges : public QObject
{
    Q_OBJECT

public:
    StringLetterChanges(QObject *parent = nullptr);
    ~StringLetterChanges();

    QString LetterChanges(QString str);
    QString LetterCapitalize(QString str);

};
