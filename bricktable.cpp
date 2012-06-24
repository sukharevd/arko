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

// bricktable.cpp
#include "bricktable.h"
#include "brick.h"
#include <QTime>
#include <math.h>
//#include <QDebug>

BrickTable::BrickTable(int* curLevel) {
    this->curLevel = curLevel;
    this->bricksAmount = 0;
    for (int i = 0; i < ROWS; i++) {
        bricks.push_back(QVector<Brick*>());
        for (int j = 0; j < COLS; j++) {
            bricks.last().push_back(NULL);
        }
    }
}

int BrickTable::getBricksAmount() {
    return bricksAmount;
}

void BrickTable::setBricksAmount(int bricksAmount) {
    this->bricksAmount = bricksAmount;
}

// TODO: maybe return boolean if zero, and linkely to controller...
void BrickTable::decrementBricksAmount() {
    this->bricksAmount--;
}

Brick* BrickTable::getAt(int row, int col) {
    return bricks.at(row).at(col);
}

void BrickTable::setAt(int row, int col, Brick* brick) {
    QVector<Brick*> temp = bricks.at(row);
    temp.replace(col, brick);
    bricks.replace(row, temp);
}

void BrickTable::regenerate() {
    double brickProbability = 0.4 * sqrt(*curLevel);   // TODO: there are only 16 level might be here due to this
    double metalProbability = 0.4 * sqrt(*curLevel);
    double dividerProbability = 0.3 * sqrt(*curLevel);
    double crapProbability = 0.2 * sqrt(*curLevel);
    double lifeProbability = 0.1 * sqrt(*curLevel);
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    bricksAmount = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            setAt(i, j, NULL);
            double rand = (double) (qrand() % 100) / 100;
            if (rand < brickProbability) {
                Brick* brick = new Brick();
                rand = (double) (qrand() % 100) / 100;
                //qDebug() << rand << " ";
                if (rand < lifeProbability) {
                    brick->setIsLife(true);
                } else if (rand < crapProbability) {
                    brick->setIsCrap(true);
                } else if (rand < dividerProbability) {
                    brick->setIsBallDivider(true);
                } else if (rand < metalProbability) {
                    brick->setLifesLeft(1000);
                } else {
                    rand = qrand() % 5;
                    brick->setLifesLeft((int)rand);
                    bricksAmount++;
                }
                setAt(i, j, brick);
            }
        }
    }
}
