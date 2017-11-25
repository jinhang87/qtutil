#include "mainwindow.h"
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile stylefile(":/spinbox.qss");
    stylefile.open(QFile::ReadOnly);
    QString qssText = QString::fromLocal8Bit(stylefile.readAll());
    a.setStyleSheet(qssText);
    stylefile.close();

    MainWindow w;
    w.show();

    return a.exec();
}
