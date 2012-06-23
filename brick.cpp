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
