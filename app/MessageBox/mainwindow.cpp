#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "messagebox.h"

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
#if 0
//    MessageBox m(MessageBox::NoIcon, "sample", QMessageBox::Ok | QMessageBox::Cancel);
//    m.show();
//    m.exec();
#else
    MessageBox::information(NULL, "Content", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
#endif
}
