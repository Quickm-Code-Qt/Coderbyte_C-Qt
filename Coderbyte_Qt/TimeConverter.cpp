#include "TimeConverter.h"

TimeConverter::TimeConverter(QObject *parent)
    : QObject(parent)
{
}

TimeConverter::~TimeConverter()
{
}

// Have the function TimeConvert(num) take the num parameter being passed and 
// return the number of hours and minutes the parameter converts to (ie. if 
// num = 63 then the output should be 1:3). Separate the number of hours 
// and minutes with a colon.
QString TimeConverter::TimeConvert(int num)
{
    QString     result;
    int         hours   = num / 60;
    int         minutes = num % 60;

    QString     minutesStr = QString::number(minutes);
    if (minutes < 10)
    {
        minutesStr = QString("0%1").arg(minutesStr);
    }

    result = QString("%1:%2").arg(QString::number(hours), minutesStr);

    return result;
}
