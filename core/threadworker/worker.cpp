

#include "worker.h"
#include <QDebug>
#include <QThread>

void Worker::start()
{
    qDebug() << "Worker::start : " << QThread::currentThreadId();
}

void Worker::dowork(const QString &parameter)
{
    qDebug() << "Worker::dowork : " << parameter;
    qDebug() << "Worker::dowork threadid : " << QThread::currentThreadId();
    emit resultReady(parameter);
}
