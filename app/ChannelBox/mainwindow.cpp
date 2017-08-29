#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "channelboxdialog.h"
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
    ChannelBoxDialog d;
    connect(&d, static_cast<void (ChannelBoxDialog::*)(const QMultiHash<ChannelBoxWidget::ChannelButtonRole, int> &hash)>(&ChannelBoxDialog::accepted),
            this, [](const QMultiHash<ChannelBoxWidget::ChannelButtonRole, int> &hash){
        qDebug() << "accepted" << hash;
    });
    connect(&d, &ChannelBoxDialog::rejected, this , [](){
        qDebug() << "rejected";
    });
    d.setSelectedMode(ChannelBoxWidget::MultiSelectedMode);
    d.exec();

}
