#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "coveragecontroldialog.h"

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

void MainWindow::on_pushButton_clicked()
{
    this->hide();
    CoverageControlDialog d;
    d.exec();
    this->show();
}
