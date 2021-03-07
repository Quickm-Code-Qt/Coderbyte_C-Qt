#pragma once

#include <QObject>

class StringQuestionMarks : public QObject
{
    Q_OBJECT

public:
    StringQuestionMarks(QObject *parent = nullptr);
    ~StringQuestionMarks();

    QString QuestionsMarks(QString str);

protected:
    bool		FindNumbersInString(const QString str, const int start, int & first, int &second);
    bool		IsQuestionMarksExist(const QString str, const int start, const int end);

};
