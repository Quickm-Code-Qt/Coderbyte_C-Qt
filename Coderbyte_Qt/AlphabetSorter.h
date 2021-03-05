#pragma once

#include <QObject>

class AlphabetSorter : public QObject
{
    Q_OBJECT

public:
    AlphabetSorter(QObject *parent = nullptr);
    ~AlphabetSorter();

    QString AlphabetSoup(QString str);
};
