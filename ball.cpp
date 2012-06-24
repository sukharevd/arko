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

// ball.cpp
#include <math.h>
#include "ball.h"
#include "shield.h"
#include "bricktable.h"
#include "brick.h"
#include "arkanoidmodel.h"
#include <QMessageBox>

Ball::Ball(ArkanoidModel* arkanoid) {
    this->arkanoid = arkanoid;
    this->x = ArkanoidModel::WIDTH >> 1;
    this->y = Shield::Y - Shield::HEIGHT - RADIUS;
    qsrand((unsigned)time(NULL));
    double randAngle = (double) qrand() / RAND_MAX;
    this->angle = - M_PI * randAngle;
    this->speed = sqrt(arkanoid->getCurLevel());
    this->dx = speed * cos(angle);
    this->dy = speed * sin(angle);
}

double Ball::getSpeed() {
    return speed;
}

void Ball::setSpeed(double speed) {
    this->speed = speed;
}

double Ball::getAngle() {
    return angle;
}

void Ball::setAngle(double angle) {
    this->angle = angle;
}

double Ball::getX() {
    return x;
}

double Ball::getY() {
    return y;
}

void Ball::setPosition(double x, double y) {
    this->x = x;
    this->y = y;
}

void Ball::move() {
    x += dx;
    y += dy;
    reflectFromWall();
    reflectFromShield();
    reflectFromBricks();

    double M_2PI = 2 * M_PI;
    while (angle > M_2PI) {
        angle -= M_2PI;
    }
    while (angle < 0) {
        angle += M_2PI;
    }
}

void Ball::reflectFromShield() {
    if (Shield::Y - y < speed) {
        Shield* shield = arkanoid->getShield();
        int x1 = shield->getPos() - (shield->getSize() >> 1);
        int x2 = shield->getPos() + (shield->getSize() >> 1);
        if (x >= x1 && x <= x2) {
            angle = 2 * M_PI - angle;
            angle -= M_PI_4 * (x - shield->getPos()) / (shield->getSize() >> 1);
            dx = speed * cos(angle);
            dy = speed * sin(angle);
        }
    }
}

void Ball::reflectFromWall() {
    if ((x + RADIUS >= ArkanoidModel::WIDTH) || (x - RADIUS <= 0)) {
        angle = M_PI - angle;
        dx = speed * cos(angle);
        dy = speed * sin(angle);
    } else if (y - RADIUS <= 0) {
        angle = 2 * M_PI - angle;
        dx = speed * cos(angle);
        dy = speed * sin(angle);
    } else if (y + RADIUS >= ArkanoidModel::HEIGHT) {
        QMessageBox* message = new QMessageBox();
        message->setText("Ball is lost");
        message->setStandardButtons(QMessageBox::Ok);
        message->setIcon(QMessageBox::Information);
        message->exec();
        delete message;
        arkanoid->setLifesLeft(arkanoid->getLifesLeft() - 1);
        arkanoid->reincarnation();
    }
}

void Ball::reflectFromBricks() {
    if ((x > BrickTable::X && x < BrickTable::X2) && (y > BrickTable::Y && y < BrickTable::Y2)) {
        int bx, by;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (!i || !j) {    // if not equal
                    bx = x + i * RADIUS;
                    by = y + j * RADIUS;
                    reflectFromBrick(bx, by, j);
                }
            }
        }
        if (arkanoid->getBrickTable()->getBricksAmount() <= 0) {
            arkanoid->setCurLevel(arkanoid->getCurLevel() + 1);
            arkanoid->getBrickTable()->regenerate();
            arkanoid->reincarnation();
        }
    }
}

void Ball::reflectFromBrick(int bx, int by, int vertical) {
    bx -= BrickTable::X;
    by -= BrickTable::Y;
    bx /= BrickTable::EL_SIZE; // column
    by /= BrickTable::EL_SIZE; // row
    if (bx < BrickTable::COLS && by < BrickTable::ROWS) {
        Brick* brick = arkanoid->getBrickTable()->getAt(by, bx);
        if (brick != NULL) {
            if (vertical) {     // if bottom or top point in this brick
                angle = 2 * M_PI - angle;
            } else {
                angle = M_PI - angle;
            }
            dx = speed * cos(angle);
            dy = speed * sin(angle);
            if (beatBrick(brick)) {
                arkanoid->getBrickTable()->setAt(by, bx, NULL);
            }
        }
    }

}

bool Ball::beatBrick(Brick* brick) {
    if (brick->getIsBallDivider()) {
        arkanoid->getBalls().push_back(new Ball(arkanoid));
        return true; //brick = NULL;
    } else if (brick->getIsCrap()) {

    } else if (brick->getIsLife()) {
        arkanoid->setLifesLeft(arkanoid->getLifesLeft() + 1);
        return true; //brick = NULL;
    } else if (brick->getLifesLeft() > 5) {

    } else {
        brick->setLifesLeft(brick->getLifesLeft() - 1);
        if (!brick->getLifesLeft() <= 0) {
            arkanoid->getBrickTable()->decrementBricksAmount();
            return true; //brick = NULL;
        }
    }
    return false;
}
