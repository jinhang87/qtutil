#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

    //w.setWindowOpacity(0.5);
    w.setWindowFlags(Qt::FramelessWindowHint);
    w.setAttribute(Qt::WA_TranslucentBackground, true);

    w.resize(QSize(800,480));
    //w.setFixedSize(QSize(800,400));
    //w.showFullScreen();

    w.show();

    return a.exec();
}
