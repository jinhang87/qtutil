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
    worker = new Worker();
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
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::sendopeatesignal);
    //启动线程
    thread->start();
    qDebug() << "MainWindow threadid : " << QThread::currentThreadId();
}

MainWindow::~MainWindow()
{
    //线程开始信号解绑定
    disconnect(thread, &QThread::started, worker, &Worker::start);
    //线程结束信号解绑定
    disconnect(thread, &QThread::finished, worker, &QObject::deleteLater);
    //线程控制信号解绑定
    disconnect(this, &MainWindow::operate, worker, &Worker::dowork);
    //线程结果上报信号解绑定
    disconnect(worker, &Worker::resultReady, this, &MainWindow::handleResult);
    //界面按钮信号解绑定
    disconnect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::sendopeatesignal);
    thread->quit();
    thread->wait();
    delete thread;
    delete worker;
    delete ui;
}

void MainWindow::sendopeatesignal()
{
    emit operate(QStringLiteral("send signal from mainwindow"));
}

void MainWindow::handleResult(const QString& parameter)
{
    qDebug() << "handleResult : " << parameter;
}



