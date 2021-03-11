#pragma once

#include <QObject>

class StringMinimumWindow : public QObject
{
    Q_OBJECT

public:
    StringMinimumWindow(QObject *parent = nullptr);
    ~StringMinimumWindow();

    QString             MinWindowSubstring(QStringList strArr);
 protected:
    QMap<char, int>     CreateCountMap(const QString s);
    QVector<QString>    ExtractWindows(const QString str, int length);
    bool                IsValidWindow(const QString window, QMap<char, int> patternMap);
};
