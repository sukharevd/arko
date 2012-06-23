// gamearea.h
#ifndef GAMEAREA_H
#define GAMEAREA_H

#include <QWidget>
class ArkanoidModel;
class Brick;

class GameArea : public QWidget
{
    Q_OBJECT
private:
    ArkanoidModel* arkanoidModel;

public:
    explicit GameArea(ArkanoidModel* arkanoidModel, QWidget *parent = 0);

    QSize minimumSizeHint() const;
    QSize sizeHint() const;
    void paintEvent(QPaintEvent * /* event */);

protected:
    void drawBall(QPainter& painter);
    void drawShield(QPainter& painter);
    void drawBricks(QPainter& painter);
    void drawBrick(Brick* brick,  int i, int j, QPainter& painter);
signals:

public slots:

};

#endif // GAMEAREA_H
