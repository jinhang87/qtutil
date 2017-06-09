#include <QCoreApplication>
#include <QTimer>
#include <QDebug>
#include "ctesttimer.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    CTestTimer *p = new CTestTimer();
    return a.exec();
}
