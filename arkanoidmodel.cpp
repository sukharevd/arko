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
