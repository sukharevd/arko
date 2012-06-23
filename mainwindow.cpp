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
