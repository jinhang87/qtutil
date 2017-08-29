#include "service.h"
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>

Service::Service(QObject *parent) : QObject(parent)
{

}

QVariantMap Service::process(const QVariantMap &request)
{
    QVariantMap reply;
    QString cmd = request["cmd"].toString();
    if (cmd.isEmpty()) {
        reply["error"] = "invalid command";
        return reply;
    }
    QString methodName = QString("process%1").arg(cmd);
    bool isOK = metaObject()->invokeMethod(this,methodName.toLatin1(),Q_RETURN_ARG(QVariantMap, reply), Q_ARG(QVariantMap, request));
    if(!isOK){
        reply["error"] = "no available method";
    }
    return reply;
}

QVariantMap Service::processSetConfig(const QVariantMap &request)
{
    QVariantMap reply;
    reply["error"] = "success";
    qDebug() << "processSetConfig";
    QString keyname = request["key"].toString();
    if (keyname.isEmpty()){
        reply["error"] = "invalid keyname";
        return reply;
    }
    m_settings[keyname] = request["value"];
    return reply;
}

QVariantMap Service::processGetConfig(const QVariantMap &request)
{
    QVariantMap reply;
    reply["error"] = "success";
    qDebug() << "processGetConfig";

    QString keyname = request["key"].toString();
    if (keyname.isEmpty()){
        reply["error"] = "invalid keyname";
        return reply;
    }
    if (m_settings.contains(keyname)){
        reply["value"] = m_settings[keyname];
        return reply;
    }
    return reply;
}

QVariantMap Service::processGetJson(const QVariantMap &request)
{
    QVariantMap reply;
    reply["error"] = "success";
    QJsonObject jObj = QJsonObject::fromVariantMap(m_settings);
    QJsonDocument jDoc(jObj);
    reply["json"] = jDoc.toJson();
    return reply;
}
