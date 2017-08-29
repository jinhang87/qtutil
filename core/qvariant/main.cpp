#include <QCoreApplication>
#include <QVariant>
#include <QDebug>

void test(void){
    QVariantMap pearMap;
    pearMap["Standard"] = 1.95;
    pearMap["Organic"] = 2.25;

    QVariantMap pearMap2;
    pearMap2["Standard"] = 1.95;
    pearMap2["Organic"] = 2.25;
    pearMap2["cc"] = pearMap;

    qDebug() << pearMap2;
    qDebug() << pearMap2["Standard"];
    qDebug() << pearMap2["cc"];
    qDebug() << qvariant_cast<QVariantMap>(pearMap2["cc"])["Standard"];
    qDebug() << pearMap2["Standard"].toDouble();
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    test();
    return a.exec();
}
