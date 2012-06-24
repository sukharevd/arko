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

// brick.cpp
#include "brick.h"

Brick::Brick()
{
    this->isBallDivider = false;
    this->isCrap = false;
    this->isLife = false;
}

int Brick::getLifesLeft() {
    return lifesLeft;
}

void Brick::setLifesLeft(int lifesLeft) {
    this->lifesLeft = lifesLeft;
}

bool Brick::getIsBallDivider() {
    return isBallDivider;
}

void Brick::setIsBallDivider(bool isBallDivider) {
    this->isBallDivider = isBallDivider;
}

bool Brick::getIsCrap() {
    return isCrap;
}

void Brick::setIsCrap(bool isCrap) {
    this->isCrap = isCrap;
}

bool Brick::getIsLife() {
    return isLife;
}

void Brick::setIsLife(bool isLife) {
    this->isLife = isLife;
}
