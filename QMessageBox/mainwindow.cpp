#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include <QMessageBox>
#include <QDebug>


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
#if 0 //直接使用静态函数
    QMessageBox::information(NULL, "Title", "Content", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
#endif

#if 1
    QMessageBox message(QMessageBox::NoIcon, "Title", "Content with icon.");
    QPixmap p = QPixmap(":/test/cc.png").scaled(QSize(30,30));
    qDebug() << p.size();
    message.setIconPixmap(p);
    message.exec();
#endif

#if 0
    QMessageBox message(QMessageBox::NoIcon, "Show Qt", "Do you want to show Qt dialog?", QMessageBox::Yes | QMessageBox::No, NULL);
    if(message.exec() == QMessageBox::Yes){
        QMessageBox::aboutQt(NULL, "About Qt");
    }
#endif
}

void MainWindow::on_pushButton_2_clicked()
{
    Dialog d;
    d.exec();
}
