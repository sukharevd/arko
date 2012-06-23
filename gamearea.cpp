// gamearea.cpp
#include <QPainter>
#include "gamearea.h"
#include "ball.h"
#include "shield.h"
#include "bricktable.h"
#include "brick.h"
#include "arkanoidmodel.h"

GameArea::GameArea(ArkanoidModel* arkanoidModel, QWidget *parent) :
    QWidget(parent)
{
    this->arkanoidModel = arkanoidModel;
}

QSize GameArea::sizeHint() const
 {
     return QSize(100, 100);
 }

QSize GameArea::minimumSizeHint() const
 {
     return QSize(100, 100);
 }

QPoint* point = new QPoint();
void GameArea::paintEvent(QPaintEvent * /* event */)
 {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.save();
    painter.drawText(QRect(5, 0, 100, 20), "Level: "+ QString::number(arkanoidModel->getCurLevel()));
    painter.drawText(QRect(250, 0, 100, 20), "Balls: "+ QString::number(arkanoidModel->getLifesLeft()));
    int x = 5;
    int y = 20;
    painter.translate(x, y);
    painter.drawRect(0, 0, ArkanoidModel::WIDTH, ArkanoidModel::HEIGHT);
    drawBricks(painter);
    drawBall(painter);
    drawShield(painter);
    painter.translate(BrickTable::X, BrickTable::Y);

    painter.restore();
    painter.setRenderHint(QPainter::Antialiasing, false);
    painter.setPen(palette().light().color());
    painter.setBrush(Qt::NoBrush);
    painter.drawRect(QRect(0, 0, width() - 1, height() - 1));
}

void GameArea::drawBall(QPainter& painter) {
    Ball* ball = arkanoidModel->getBalls().at(0);
    int radius = Ball::RADIUS;
    point->setX((int)ball->getX());
    point->setY((int)ball->getY());

    QLinearGradient linearGradient(ball->getX(), ball->getX(), radius, radius);
    linearGradient.setColorAt(0, Qt::green);
    linearGradient.setColorAt(1, Qt::darkGreen);
    painter.setBrush(linearGradient);
    painter.drawEllipse(*point, radius, radius);
}

void GameArea::drawShield(QPainter& painter) {
    Shield* shield = arkanoidModel->getShield();
    int radius = shield->getSize();
    int x = shield->getPos() - (shield->getSize() >> 1);
    int y = Shield::Y;
    QRect rect(x, y, radius, Shield::HEIGHT);

    QRadialGradient linearGradient(shield->getPos(), y, radius);
    linearGradient.setColorAt(0.0, Qt::white);
    linearGradient.setColorAt(0.7, Qt::darkRed);
    painter.setBrush(linearGradient);
    painter.drawRect(rect);
}

void GameArea::drawBricks(QPainter& painter) {
    BrickTable* bricks = arkanoidModel->getBrickTable();
    Brick* curBrick;
    for (int i = 0; i < BrickTable::ROWS; i++) {
        for (int j = 0; j < BrickTable::COLS; j++) {
            curBrick = bricks->getAt(i, j);
            if (curBrick != NULL) {
                drawBrick(curBrick, i, j, painter);
            }
        }
    }
}

void GameArea::drawBrick(Brick* brick, int i, int j, QPainter& painter) {
    int x = BrickTable::X + j * BrickTable::EL_SIZE;
    int y = BrickTable::Y + i * BrickTable::EL_SIZE;
    int size = BrickTable::EL_SIZE;
    QRect rect(x, y, size, size);

    QLinearGradient linearGradient(BrickTable::X, BrickTable::Y, x, y);
    linearGradient.setColorAt(0, Qt::white);
    if (brick->getIsBallDivider()) {
        linearGradient.setColorAt(1, Qt::blue);
    } else if (brick->getIsCrap()) {
        linearGradient.setColorAt(1, Qt::black); //return;
    } else if (brick->getIsLife()) {
        linearGradient.setColorAt(1, Qt::red);
    } else if (brick->getLifesLeft() > 5) {
        linearGradient.setColorAt(1, Qt::black);
    } else {
        linearGradient.setColorAt(1, Qt::darkCyan);
    }
    painter.setBrush(linearGradient);
    painter.drawRect(rect);
}
