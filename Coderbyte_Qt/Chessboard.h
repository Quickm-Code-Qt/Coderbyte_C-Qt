#pragma once

#include <QObject>

class Chessboard : public QObject
{
    Q_OBJECT

public:
    Chessboard(QObject *parent = nullptr);
    ~Chessboard();

    int ChessboardTraveling(QString str);

    protected:
    int ComputeUniqueWays(const int k, const int n);

};
