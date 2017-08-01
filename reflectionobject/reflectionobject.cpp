#include "reflectionobject.h"
#include <QDebug>

ReflectionObject::ReflectionObject(QObject *parent) : QObject(parent)
{

}

int ReflectionObject::getId() const
{
    return id;
}

void ReflectionObject::setId(int value)
{
    id = value;
}

QString ReflectionObject::getName() const
{
    qDebug() << "name = " << name;
    return name;
}

void ReflectionObject::setName(const QString &value)
{
    name = value;
}
