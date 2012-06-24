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

// arkanoidmodel.h
#ifndef ARKANOIDMODEL_H
#define ARKANOIDMODEL_H

#include <QVector>
class Ball;
class Shield;
class BrickTable;

class ArkanoidModel
{
private:
    QVector<Ball*> balls;
    Shield* shield;
    BrickTable* bricks;
    int curLevel;
    int lifesLeft;
public:
    static const int WIDTH = 300;
    static const int HEIGHT = 300;

    ArkanoidModel();

    QVector<Ball*> getBalls();
    void setBalls(QVector<Ball*> balls);
    Shield* getShield();
    void setShield(Shield* shield);
    BrickTable* getBrickTable();
    void setBrickTable(BrickTable* bricks);
    int getCurLevel();
    void setCurLevel(int level);
    int getLifesLeft();
    void setLifesLeft(int lifesLeft);

    void restart();
    void reincarnation();
    void update();
    void moveShieldRight();
    void moveShieldLeft();
    void shake();
};

#endif // ARKANOIDMODEL_H
