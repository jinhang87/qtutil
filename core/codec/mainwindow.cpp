#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "utf8dialog.h"
#include "gbkdialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //QtCreator 配置： 工具->选项->文件编码->默认编码->GBK...
    //setStyleSheet("QLabel { border-image: url(:/剪切-click-.png)}");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonUtf8dialog_clicked()
{
    Utf8Dialog d;
    d.exec();
}

void MainWindow::on_pushButtonGbkdialog_clicked()
{
    GbkDialog d;
    d.exec();
}
