#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QHelpEvent>
#include <QToolTip>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton->setToolTip("tips");
    setStyleSheet("QToolTip{background-image: url(:/image/image.png);}");
    tips = new QPushButton("tip button", this);
    tips->setWindowFlags(Qt::ToolTip);
    tipstip = new QLabel("tipstip", this);
    tipstip->hide();
    connect(tips, &QPushButton::clicked, this, [=](){
        tipstip->show();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::event(QEvent *event)
{
    if (event->type() == QEvent::ToolTip) {
        qDebug() << "tool tip show";
        QHelpEvent *helpEvent = static_cast<QHelpEvent *>(event);
        //int index = itemAt(helpEvent->pos());
        qDebug() << "tool tip show pos = " << helpEvent->pos();
        QToolTip::showText(helpEvent->globalPos(), "radio tips");
    }
    return QWidget::event(event);
}

void MainWindow::on_radioButton_clicked()
{
    //QToolTip::showText(ui->radioButton->)
}

void MainWindow::on_pushButton_clicked()
{

    tips->move(geometry().x()+200,geometry().y());
    tips->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    tips->move(geometry().x()+100,geometry().y()+100);
    tips->show();
}
