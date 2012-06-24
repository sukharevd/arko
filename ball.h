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

// ball.h
#ifndef BALL_H
#define BALL_H

class ArkanoidModel;
class Brick;

class Ball
{
private:
    ArkanoidModel* arkanoid;
    double speed;
    double angle;
    double x;
    double y;
    double dx;
    double dy;

public:
    static const int RADIUS = 4;

    Ball(ArkanoidModel* arkanoid);

    double getSpeed();
    void setSpeed(double speed);
    double getAngle();
    void setAngle(double angle);
    double getX();
    double getY();
    void setPosition(double x, double y);

    void move();

protected:
    void reflectFromShield();
    void reflectFromWall();
    void reflectFromBricks();
    void reflectFromBrick(int bx, int by, int vertical);
    bool beatBrick(Brick* brick);
};

#endif // BALL_H
