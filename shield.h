// shield.h
#ifndef SHIELD_H
#define SHIELD_H
#include "arkanoidmodel.h"
//class ArkanoidModel;

class Shield
{
private:
    int* curLevel;
    int size; // must be const and be calculated depend on curLevel
    int pos;  // pos | x?
public:
    static const int HEIGHT = 16;
    static const int Y = ArkanoidModel::HEIGHT - HEIGHT;

    Shield(int* curLevel);

    int getSize();
    void setSize(int size);
    int getPos();
    void setPos(int pos);

    void moveLeft();
    void moveRight();
};
#endif // SHIELD_H
