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

// gamearea.h
#ifndef GAMEAREA_H
#define GAMEAREA_H

#include <QWidget>
class ArkanoidModel;
class Brick;

class GameArea : public QWidget
{
    Q_OBJECT
private:
    ArkanoidModel* arkanoidModel;

public:
    explicit GameArea(ArkanoidModel* arkanoidModel, QWidget *parent = 0);

    QSize minimumSizeHint() const;
    QSize sizeHint() const;
    void paintEvent(QPaintEvent * /* event */);

protected:
    void drawBall(QPainter& painter);
    void drawShield(QPainter& painter);
    void drawBricks(QPainter& painter);
    void drawBrick(Brick* brick,  int i, int j, QPainter& painter);
signals:

public slots:

};

#endif // GAMEAREA_H
