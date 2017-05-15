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
    worker = new Worker(this);
    thread = new QThread;
    worker->moveToThread(thread);
    connect(thread, &QThread::started, worker, &Worker::start);
    connect(thread, &QThread::finished, worker, &QObject::deleteLater);
    connect(this, &MainWindow::operate, worker, &Worker::dowork);
    connect(worker, &Worker::resultReady, this, &MainWindow::handleResult);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::sendopeatesignal);
    thread->start();
    qDebug() << "MainWindow threadid : " << QThread::currentThreadId();
}

MainWindow::~MainWindow()
{
    thread->quit();
    thread->wait();
    delete thread;
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



