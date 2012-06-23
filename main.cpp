// main.cpp
#include <QtGui/QApplication>
#include "mainwindow.h"
#include "arkanoidmodel.h"

ArkanoidModel arkanoidModel;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w(&arkanoidModel);
    w.show();

    return a.exec();
}
