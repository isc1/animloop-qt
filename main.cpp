#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;  // most of the program lives in mainwindow.cpp and mainwindow.h
    w.show();

    return a.exec();  // hand over control of our app to Qt engine
}
