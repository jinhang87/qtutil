#include "widget.h"
#include "widgeta.h"
#include "widgetb.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    //指定某个控件透明，windows ok
//    Widget w;
//    w.show();

    //窗体透明，窗体的控件透明，windows ok
    WidgetA w;
    w.show();

//    //窗体透明，窗体的控件不透明，windows ok
//    WidgetB w;
//    w.show();


    return a.exec();
}
