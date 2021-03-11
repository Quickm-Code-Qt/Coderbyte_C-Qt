#pragma once

#include <QObject>

class TreeGraphs : public QObject
{
    Q_OBJECT

public:
    TreeGraphs(QObject *parent = nullptr);
    ~TreeGraphs();

    QString                             TreeConstructor(QStringList strArr);


 protected:
    QVector<QPair<int, int>>	        ParseInput(QVector<QString> input);
    void								ParseInputString(QString str, int & num1, int & num2);

};
