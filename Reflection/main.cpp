#include <QCoreApplication>
#include <service.h>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Service service;
    QVariantMap request1;
    request1["cmd"] = "SetConfig";
    request1["key"] = "search-engine";
    request1["value"] = "www.google.com";
    QVariantMap reply1 = service.process(request1);
    qDebug() << reply1;

    QVariantMap request3;
    request3["cmd"] = "GetConfig";
    request3["key"] = "search-engine";
    QVariantMap reply3 = service.process(request3);
    qDebug() << reply3;

    QVariantMap requestJson;
    request3["cmd"] = "GetJson";
    QVariantMap replyJson = service.process(request3);
    qDebug() << replyJson["json"].toByteArray();

    return a.exec();
}
