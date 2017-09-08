#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "progressdialog.h"

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
    int numFiles = 1000000000;
    ProgressDialog progress("", 0, numFiles);
    progress.show();
    progress.setWindowModality(Qt::WindowModal);

    for (int i = 0; i < numFiles; i++) {
        progress.setValue(i);
        //QCoreApplication::processEvents();
        if (progress.wasCanceled())
            break;
        //... copy one file
    }
    progress.setValue(numFiles);
}
