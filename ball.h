// ball.h
#ifndef BALL_H
#define BALL_H

class ArkanoidModel;
class Brick;

class Ball
{
private:
    ArkanoidModel* arkanoid;
    double speed;
    double angle;
    double x;
    double y;
    double dx;
    double dy;

public:
    static const int RADIUS = 4;

    Ball(ArkanoidModel* arkanoid);

    double getSpeed();
    void setSpeed(double speed);
    double getAngle();
    void setAngle(double angle);
    double getX();
    double getY();
    void setPosition(double x, double y);

    void move();

protected:
    void reflectFromShield();
    void reflectFromWall();
    void reflectFromBricks();
    void reflectFromBrick(int bx, int by, int vertical);
    bool beatBrick(Brick* brick);
};

#endif // BALL_H
