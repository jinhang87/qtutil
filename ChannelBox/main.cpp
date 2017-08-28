#include "widget.h"
#include <QApplication>
#include "channelboxdialog.h"
#include "mainwindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Widget w;
    //ChannelBoxDialog w;
    MainWindow w;
    w.show();

    return a.exec();
}
