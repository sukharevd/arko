// shield.cpp
#include "shield.h"
#include "arkanoidmodel.h"
//#include "math.h"

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
    pos -= 10;
}

void Shield::moveRight() {
    pos += 10;
}
