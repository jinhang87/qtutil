#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QThread>
#include "worker.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
#ifdef USE_QPOINTER
    worker = new Worker(this);
#else
    worker = new Worker;
#endif
    thread = new QThread;

    //线程和具体任务操作绑定
    worker->moveToThread(thread);
    //线程开始信号绑定
    connect(thread, &QThread::started, worker, &Worker::start);
    //线程结束信号绑定
    connect(thread, &QThread::finished, worker, &QObject::deleteLater);
    //线程控制信号绑定
    connect(this, &MainWindow::operate, worker, &Worker::dowork);
    //线程结果上报信号绑定
    connect(worker, &Worker::resultReady, this, &MainWindow::handleResult);
    //界面按钮信号绑定
    connect(ui->pushButton, &QPushButton::clicked, this, [=](){
        emit this->operate(QStringLiteral("send signal from mainwindow"));
    });
    //启动线程
    thread->start();
    qDebug() << "MainWindow threadid : " << QThread::currentThreadId();
}

MainWindow::~MainWindow()
{
    thread->quit();
    thread->wait();
    delete thread; //emit QThread::finished
    delete ui;
    qDebug() << "~MainWindow()";
}

void MainWindow::handleResult(const QString& parameter)
{
    qDebug() << "handleResult : " << parameter;
}



