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

// shield.cpp
#include "shield.h"
#include "arkanoidmodel.h"
#include <algorithm>
using std::max;
using std::min;

Shield::Shield(int* curLevel) {
    this->curLevel = curLevel;
    this->pos = ArkanoidModel::WIDTH >> 1;
    this->size = 128;//(int) (32.0 / sqrt(*curLevel));
}

int Shield::getSize() {
    return size;
}

void Shield::setSize(int size) {
    this->size = size;
}

int Shield::getPos() {
    return pos;
}

void Shield::setPos(int pos) {
    this->pos = pos;
}

void Shield::moveLeft() {
    pos = max(pos - 10, this->size >> 1);
}

void Shield::moveRight() {
    pos = min(pos + 10, ArkanoidModel::WIDTH - (this->size >> 1));
}
