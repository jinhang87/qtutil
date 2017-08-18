#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "daytrackgroup.h"
#include "timetip.h"
#include <QDebug>
#include <QMouseEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    qDebug() << "mousePressEvent" << e->pos();
}

void MainWindow::on_pushButton_clicked()
{

}
