// brick.h
#ifndef BRICK_H
#define BRICK_H

class Brick
{
private:
    int lifesLeft;
    bool isBallDivider;
    bool isCrap;
    bool isLife;

public:
    Brick();

    int getLifesLeft();
    void setLifesLeft(int lifesLeft);
    bool getIsBallDivider();
    void setIsBallDivider(bool isBallDivider);
    bool getIsCrap();
    void setIsCrap(bool isCrap);
    bool getIsLife();
    void setIsLife(bool isLife);
};

#endif // BRICK_H
