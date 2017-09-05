#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "videomenuwidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    w = new VideoMenuWidget(this);
//    w->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //w->show();
    VideoMenuWidget w;
    w.show();
    w.exec();
}
