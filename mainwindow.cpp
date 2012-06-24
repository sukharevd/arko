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

// mainwindow.cpp
#include <QMessageBox>
#include <QShortcut>
#include <QTimer>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "arkanoidmodel.h"

MainWindow::MainWindow(ArkanoidModel* arkanoidModel, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->arkanoidModel = arkanoidModel;
    leftArrow = new QShortcut(Qt::Key_Left, this, SLOT(on_left_arrow()));
    rightArrow = new QShortcut(Qt::Key_Right, this, SLOT(on_right_arrow()));
    timer = new QTimer();
    timer->setInterval(5);
    connect(timer, SIGNAL(timeout()), this, SLOT(timer_ticked()));
    gameArea = new GameArea(arkanoidModel);
    setCentralWidget(gameArea);
    this->setWindowTitle("Arko");
}

MainWindow::~MainWindow()
{
    delete ui;
    delete leftArrow;
    delete rightArrow;
    delete timer;
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox* message = new QMessageBox();
    message->setWindowTitle("About");
    message->setText("Arko\nCopyright(c) Dmitriy Sukharev, 2010.");
    message->setStandardButtons(QMessageBox::Ok);
    message->setIcon(QMessageBox::Information);
    message->exec();
    delete message;
}

void MainWindow::on_actionStart_triggered()
{
    timer->start();
    arkanoidModel->restart();
}

void MainWindow::on_actionPause_triggered()
{
    if (timer->isActive()) {
        timer->stop();
    } else {
        timer->start();
    }
}

void MainWindow::on_actionQuit_triggered()
{
    exit(0);
}

void MainWindow::on_left_arrow()
{
    arkanoidModel->moveShieldLeft();
}

void MainWindow::on_right_arrow()
{
    arkanoidModel->moveShieldRight();
}

void MainWindow::timer_ticked()
{
    arkanoidModel->update();
    static int ctr = 0;
    if ((ctr++) & 1) {
        gameArea->repaint();
    }
}

void MainWindow::on_actionShake_triggered()
{
    arkanoidModel->shake();
}
