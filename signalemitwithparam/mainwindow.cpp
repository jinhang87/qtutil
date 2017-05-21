#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(this, &send, this, &recv);
    connect(ui->pushButton, &QPushButton::clicked, this, [=](){
        EmitData data;
        qDebug() << "send signal";
        emit this->send(data);
    });
}

void MainWindow::recv(EmitData data)
{
    Q_UNUSED(data);
    qDebug() << "recv signal";
}

MainWindow::~MainWindow()
{
    delete ui;
}
