#include "widget.h"
#include <QApplication>
#include "channelboxdialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Widget w;
    ChannelBoxDialog w;
    w.show();

    return a.exec();
}
