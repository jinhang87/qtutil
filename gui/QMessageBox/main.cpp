#include "mainwindow.h"
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QFile qss(":/style/style.qss");
    qss.open(QFile::ReadOnly);

    a.setStyleSheet(qss.readAll());
    qss.close();

    return a.exec();
}
