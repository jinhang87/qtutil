#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int i = 0;
    for(i = 0; i< 7 ; i++)
    {
        QSize iconsize(64,64);
        QPixmap pix(iconsize);
        QPainter painter(&pix);
        QLinearGradient gradient(0,0, 0, iconsize.height());
        gradient.setColorAt(0.0, QColor(240, 240, 240));
        gradient.setColorAt(1.0, QColor(224, 224, 224));
        QBrush brush(gradient);
        painter.fillRect(QRect(QPoint(0, 0), iconsize), brush);
        QListWidgetItem *item = new QListWidgetItem;
        item->setIcon(QIcon(pix));
        item->setText("2112");
        ui->listWidget->addItem(item);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
