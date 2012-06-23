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
