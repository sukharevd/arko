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

// arkanoidmodel.cpp
#include "arkanoidmodel.h"
#include "ball.h"
#include "shield.h"
#include "bricktable.h"
#include <QVector>

ArkanoidModel::ArkanoidModel() {
    shield = new Shield(&curLevel);
    bricks = new BrickTable(&curLevel);
    restart();
}

QVector<Ball*> ArkanoidModel::getBalls() {
    return balls;
}

void ArkanoidModel::setBalls(QVector<Ball*> balls) {
    this->balls = balls;
}

Shield* ArkanoidModel::getShield() {
    return shield;
}

void ArkanoidModel::setShield(Shield* shield) {
    this->shield = shield;
}

BrickTable* ArkanoidModel::getBrickTable() {
    return bricks;
}

void ArkanoidModel::setBrickTable(BrickTable* bricks) {
    this->bricks = bricks;
}

int ArkanoidModel::getCurLevel() {
    return curLevel;
}

void ArkanoidModel::setCurLevel(int curLevel) {
    this->curLevel = curLevel;
}

int ArkanoidModel::getLifesLeft() {
    return lifesLeft;
}

void ArkanoidModel::setLifesLeft(int lifesLeft) {
    this->lifesLeft = lifesLeft;
}

void ArkanoidModel::update() {
    QVector<Ball*>::iterator i = balls.begin();
    while (i != balls.end()) {
        (*i)->move();
        ++i;
    }
}

void ArkanoidModel::moveShieldRight() {
    shield->moveRight();
}

void ArkanoidModel::moveShieldLeft() {
    shield->moveLeft();
}

void ArkanoidModel::shake() {
    for (int i = 0; i < balls.size(); i++) {
        balls.at(i)->setPosition(balls.at(i)->getX() + 5, balls.at(i)->getY() - 5);

    };
}

void ArkanoidModel::restart() {
    curLevel = 1;
    lifesLeft = 10;
    reincarnation();
    bricks->regenerate();
}

void ArkanoidModel::reincarnation() {
    for (int i = 0; i < balls.size(); i++) {
        delete balls.at(i);
    }
    balls.erase(balls.begin(), balls.end());
    Ball* ball = new Ball(this);
    balls.push_back(ball);
    shield->setPos(ArkanoidModel::WIDTH >> 1);
}
