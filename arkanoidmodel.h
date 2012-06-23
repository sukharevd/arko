// arkanoidmodel.h
#ifndef ARKANOIDMODEL_H
#define ARKANOIDMODEL_H

#include <QVector>
class Ball;
class Shield;
class BrickTable;

class ArkanoidModel
{
private:
    QVector<Ball*> balls;
    Shield* shield;
    BrickTable* bricks;
    int curLevel;
    int lifesLeft;
public:
    static const int WIDTH = 300;
    static const int HEIGHT = 300;

    ArkanoidModel();

    QVector<Ball*> getBalls();
    void setBalls(QVector<Ball*> balls);
    Shield* getShield();
    void setShield(Shield* shield);
    BrickTable* getBrickTable();
    void setBrickTable(BrickTable* bricks);
    int getCurLevel();
    void setCurLevel(int level);
    int getLifesLeft();
    void setLifesLeft(int lifesLeft);

    void restart();
    void reincarnation();
    void update();
    void moveShieldRight();
    void moveShieldLeft();
    void shake();
};

#endif // ARKANOIDMODEL_H
