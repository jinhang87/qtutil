#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
#if 0
    //创建翻译器
    QTranslator tsor;

    //加载语言包
    if(tsor.load("i18n_zh_cn.qm")){
        //安装翻译器
        a.installTranslator(&tsor);
        qDebug() << "install ok!";
    }else{
        qDebug() << "install not ok!";
    }
#endif
    qDebug() << QObject::tr("plugins");
    qDebug() << "ok";

    MainWindow w;
    w.show();

    return a.exec();
}
