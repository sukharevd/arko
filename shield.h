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

// shield.h
#ifndef SHIELD_H
#define SHIELD_H
#include "arkanoidmodel.h"
//class ArkanoidModel;

class Shield
{
private:
    int* curLevel;
    int size; // must be const and be calculated depend on curLevel
    int pos;  // pos | x?
public:
    static const int HEIGHT = 16;
    static const int Y = ArkanoidModel::HEIGHT - HEIGHT;

    Shield(int* curLevel);

    int getSize();
    void setSize(int size);
    int getPos();
    void setPos(int pos);

    void moveLeft();
    void moveRight();
};
#endif // SHIELD_H
