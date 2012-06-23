// bricktable.h
#ifndef BRICKTABLE_H
#define BRICKTABLE_H

#include <QVector>
class Brick;

class BrickTable
{
private:
    int* curLevel;
    int bricksAmount;
    QVector<QVector<Brick*> > bricks;

public:
    static const int X = 20;
    static const int Y = 20;
    static const int COLS = 20;
    static const int ROWS = 8;
    static const int EL_SIZE = 12;
    static const int X2 = X + EL_SIZE * COLS;
    static const int Y2 = Y + EL_SIZE * ROWS;

    BrickTable(int* curLevel);

    int getBricksAmount();
    void setBricksAmount(int bricksAmout);
    void decrementBricksAmount();
    Brick* getAt(int row, int col);
    void setAt(int row, int col, Brick* brick);
    void regenerate();
};

#endif // BRICKTABLE_H
