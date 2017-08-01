#include <QCoreApplication>
#include "reflectionobject.h"
#include <QDebug>
#include <QMetaObject>
#include <QMetaMethod>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ReflectionObject obj;
    const QMetaObject *metaobj = obj.metaObject();

    QMetaObject::invokeMethod(&obj, "getName");

    int i = 0;
    for(i = 0; i < metaobj->methodCount(); i++){
        QMetaMethod method = metaobj->method(i);
        qDebug() <<"typeName = " << method.typeName();
        //qDebug() <<"signature = " << method.signature();
        qDebug() <<"methodType = " << method.methodType();
    }


    return a.exec();
}
