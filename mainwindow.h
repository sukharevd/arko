// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QShortcut>
#include "gamearea.h"

class ArkanoidModel;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(ArkanoidModel* arkanoidModel, QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    GameArea* gameArea;
    QShortcut* leftArrow;
    QShortcut* rightArrow;
    QTimer* timer;
    ArkanoidModel* arkanoidModel;

private slots:
    void on_actionShake_triggered();
    void on_actionQuit_triggered();
    void on_actionPause_triggered();
    void on_actionStart_triggered();
    void on_actionAbout_triggered();
    void on_left_arrow();
    void on_right_arrow();
    void timer_ticked();
};

#endif // MAINWINDOW_H
