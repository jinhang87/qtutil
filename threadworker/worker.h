#ifndef WORKER_H
#define WORKER_H
#include <QObject>

// May be A Time-consuming task
class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = 0):QObject(parent) {}
    virtual ~Worker(){}

signals:
    void resultReady(const QString &parameter);

public slots :
    void start();
    void dowork(const QString &parameter);
};


#endif // WORKER_H
