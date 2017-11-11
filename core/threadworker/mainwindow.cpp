#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QThread>
#include "worker.h"
#include <QDebug>
#include <QSharedPointer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
#ifdef USE_QPOINTER
    //worker = new Worker(this);
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


    m_dialogWait.reset();

    //线程结果上报信号绑定
    connect(worker, &Worker::resultReady, this, [=](const QString &parameter){
        this->handleResult(parameter);
        m_dialogWait.reset();
    });
    //界面按钮信号绑定
    connect(ui->pushButton, &QPushButton::clicked, this, [=](){
        emit this->operate(QStringLiteral("send signal from pushButton"));
        m_dialogWait.reset(new QProgressDialog);
        m_dialogWait->setModal(true);
        m_dialogWait->setWindowTitle("Wait...");
        m_dialogWait->setRange(0, 0);
        m_dialogWait->setLabelText(QStringLiteral("Wait..."));
        m_dialogWait->show();
        m_dialogWait->exec();
    });
    //测试invoke,可以避免定义信号operate
    connect(ui->pushButtonInvoke, &QPushButton::clicked, this, [=](){
        QMetaObject::invokeMethod(worker, "dowork", Q_ARG(const QString &, "send signal from pushButtonInvoke"));
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




void MainWindow::on_pushButtonInvoke_clicked()
{
}
