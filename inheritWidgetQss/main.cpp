#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    qApp->setStyleSheet("QWidget{background-color: blue} SubWidget{background-color: gray}");

    return a.exec();
}
