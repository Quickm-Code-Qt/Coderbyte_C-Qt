#pragma once

#include <QObject>

class UsernameValidation : public QObject
{
    Q_OBJECT

public:
    UsernameValidation(QObject *parent = nullptr);
    ~UsernameValidation();

    QString CodelandUsernameValidation(QString str);

 protected:
    bool validateLength(QString str);
    bool validateStartWithLetter(QString str);
    bool validateOnlyValidCharacters(QString str);
    bool validateEndCharacter(QString str);

};
