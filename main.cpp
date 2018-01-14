//Tutorial Code from "MASTERING QT5: CREATE STUNNING CROSS-PLATFORM APPLICATIONS"
//To Do List Program
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
