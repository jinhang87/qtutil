#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->widget->setCurrentPage(1);
    ui->widget->setTotalPage(32);
}

MainWindow::~MainWindow()
{
    delete ui;
}
