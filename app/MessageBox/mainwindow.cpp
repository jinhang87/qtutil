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
    MessageBox m(MessageBox::NoIcon, "sample", QMessageBox::Ok | QMessageBox::Cancel);
    m.show();
    m.exec();
}
