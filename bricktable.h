/****************************************************************************
 **
 ** Copyright (C) 2010-2012 Dmitriy Sukharev.
 ** All rights reserved.
 ** Contact: Dmitriy Sukharev (ecuna@mail.ru)
 **
 ** This file is part of Arko.
 **
 ** Arko is free software: you can redistribute it and/or modify
 ** it under the terms of the GNU Lesser General Public License as published
 ** by the Free Software Foundation, either version 3 of the License, or
 ** (at your option) any later version.
 **
 ** Arko is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY; without even the implied warranty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 ** GNU Lesser General Public License for more details.
 **
 ** You should have received a copy of the GNU Lesser General Public License
 ** along with Arko.  If not, see <http://www.gnu.org/licenses/>.
 **
 ****************************************************************************/

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
