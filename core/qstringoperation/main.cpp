#include <QCoreApplication>
#include <QDebug>
#include <string.h>
#include <QTextCodec>

void caseQByteArrayContain0()
{
//QByteArray can contains "我0"
    QByteArray bytes;
    bytes.resize(5);
    bytes[0] = '1';
    bytes[1] = '2';
    bytes[2] = '3';
    bytes[3] = '\0';
    bytes[4] = 'a';
    qDebug() << bytes;
}

void caseQString2stdstring()
{
//QString -> std::string
    QString s1("hello");
    std::string str1 = s1.toStdString();
    qDebug() << "str1 = " << str1.c_str();

//std::string -> QString
    std::string str2 = "abcd";
    QString s2 = QString::fromStdString(str2);
    qDebug() << "s2 = " << s2;
}

void caseQString2Constcharptr()
{
//QString -> const char*
    QString s1("hello");
    const char* pstr1_1 = qPrintable(s1);
    qDebug() << "pstr1_1 = " << pstr1_1; // print "hello"

#if 0  // warning !!!  this is errror, pstr1_3 print error string;
    QString s1_2("hello");
    const char* pstr1_2 = s1_2.toLocal8Bit().constData();
    qDebug() << "pstr1_2 = " << pstr1_2; // print not right!
#endif

    QString s1_2("hello");
    qDebug() << "s1_2 = " << s1_2.toLocal8Bit().constData(); // print "hello"

    //QString to ChineseChar
    QTextCodec *tc = QTextCodec::codecForName("UTF8");
    QString s1_3("hello我");
    QByteArray b1_3 = tc->fromUnicode( s1_3 );
    qDebug() << "s1_3 = " << b1_3.constData(); // print "hello我" in win7 cmd

//const char* -> QString
    const char* pstr2 = "abcd";
    QString s2(pstr2);
    qDebug() << "s2 = " << s2;
}


void caseQByteArray2QString()
{
//QByteArray -> QString
    QByteArray cstr1("abcd");
    QString s1 = cstr1;

    QByteArray cstr2("abcd");
    QString s2;
    s2.prepend(cstr2);

//QString -> QByteArray
    QString s4("hello");
    QByteArray cstr4 = s4.toLatin1();
    qDebug() << cstr4;
}

void caseQStringFormat()
{
    QString str = "User: ";
    str.sprintf("%s %.1f%%"  , "perfect competition"  , 100.0);
    qDebug() << str;
    str = QString("%1 %2 (%3s-%4s)").arg("permissive").arg("society").arg(1950).arg(1970);
    qDebug() << str;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //caseQString2stdstring();
    caseQString2Constcharptr();
    //caseQByteArrayContain0();
    //caseQByteArray2QString();
    //caseQStringFormat();
    return a.exec();
}
