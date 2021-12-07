#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.initgame();
    w.initScene();
    w.playgame();
    return a.exec();
}
