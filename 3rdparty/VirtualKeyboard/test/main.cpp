#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    qputenv("QT_IM_MODULE",QByteArray("Qt5Input")); // 起不来

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
