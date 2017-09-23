

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
    for(int i = 0; i<100000; i++){
        qDebug() << i;
    }
    emit resultReady(parameter);
}
