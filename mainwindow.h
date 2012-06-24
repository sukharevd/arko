/****************************************************************************
 **
 ** Copyright (C) 2010-2012 Dmitriy Sukharev.
 ** All rights reserved.
 ** Contact: Dmitriy Sukharev (ecuna@mail.ru)
 **
 ** This file is part of Arko.
 **
 ** Arko is free software: you can redistribute it and/or modify
 ** it under the terms of the GNU Lesser General Public License as published
 ** by the Free Software Foundation, either version 3 of the License, or
 ** (at your option) any later version.
 **
 ** Arko is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY; without even the implied warranty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 ** GNU Lesser General Public License for more details.
 **
 ** You should have received a copy of the GNU Lesser General Public License
 ** along with Arko.  If not, see <http://www.gnu.org/licenses/>.
 **
 ****************************************************************************/

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
