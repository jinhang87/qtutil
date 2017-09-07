#include "widget.h"
#include "widgeta.h"
#include "widgetb.h"
#include "widgetc.h"
#include "widgetd.h"
#include "widgetqss.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

#define TEST 2

#if (TEST==1)
    //指定某个控件透明，windows ok
    Widget w;
    w.show();
#elif (TEST==2)
    //窗体透明，窗体的控件透明，windows ok
    //embeded linux 正常
    //windows 正常
    WidgetA w;
    w.show();
#elif (TEST==3)
    //窗体透明，窗体的控件不透明，windows ok
    WidgetB w;
    w.show();
#elif (TEST==4)
    //窗体不透明，窗体的局部区域透明，窗体上的控件不透明
    //embeded linux 正常
    //windows 局部区域变黑，控件显示不了
    WidgetC w;
    w.show();
#elif (TEST==5)
    //窗体透明，控件不透明
    //embeded linux 正常
    //windows 背景变黑，控件显示不了
    WidgetD w;
    w.show();
#elif (TEST==6)
    //控件透明颜色属性
    WidgetQss w;
    w.show();
#endif
    return a.exec();
}
