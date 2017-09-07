#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QRegExp>

void testRegexCapture1()
{
    QString pattern("(.*)=(.*)");
    QRegExp rx(pattern);

    QString str("a=100");
    int pos = str.indexOf(rx);              // 0, position of the first match.
    // Returns -1 if str is not found.
    // You can also use rx.indexIn(str);
    qDebug() << pos;
    if ( pos >= 0 ){
        qDebug() << rx.matchedLength();     // 5, length of the last matched string
        // or -1 if there was no match
        qDebug() << rx.capturedTexts();     // QStringList("a=100", "a", "100"),
        //   0: text matching pattern
        //   1: text captured by the 1st ()
        //   2: text captured by the 2nd ()

        qDebug() << rx.cap(0);              // a=100, text matching pattern
        qDebug() << rx.cap(1);              // a, text captured by the nth ()
        qDebug() << rx.cap(2);              // 100,

        qDebug() << rx.pos(0);              // 0, position of the nth captured text
        qDebug() << rx.pos(1);              // 0
        qDebug() << rx.pos(2);              // 2
    }
}

void testRegexCapture2()
{
    QRegExp rx("([xyz]+)=(\\d+)");
    QString test("x=23,y=54,z=32,c=x");

    int pos = test.indexOf(rx);
    if(pos >= 0){
        qDebug() << rx.matchedLength();
        qDebug() << rx.capturedTexts();
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    testRegexCapture1();
    testRegexCapture2();

    return a.exec();
}
