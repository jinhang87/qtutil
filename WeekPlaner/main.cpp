#include "mainwindow.h"
#include "mainwindowweekplaner.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    MainWindowWeekPlaner w;
    w.show();

    return a.exec();
}
