#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "daytrackgroup.h"
#include "timetip.h"
#include <QDebug>
#include <QMouseEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dayGroup = new DayTrackGroup(this);
    dayGroup->addDayTrack(ui->frame, 1);
    dayGroup->addDayTrack(ui->frame_2, 2);
    dayGroup->addDayTrack(ui->frame_3, 3);
    tip = new TimeTip(this);
    connect(dayGroup, &DayTrackGroup::DayTrackClicked, this, [=](int id, QRect rect){
        DayTrack *dayTrack = dayGroup->dayTrack(id);
        QPoint p = dayTrack->mapTo(this, rect.topLeft());
        tip->setCentralRect(QRect(p, rect.size()));
        tip->show();
    });


    connect(dayGroup, &DayTrackGroup::DayTrackOutSideClicked, this, [=](){
        tip->hide();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    qDebug() << "mousePressEvent" << e->pos();
}

void MainWindow::on_pushButton_clicked()
{
    QPoint p = ui->frame->mapTo(this, ui->frame->pos());
    qDebug() << "MainWindow frame" << ui->frame->pos() << ui->frame->geometry() << p;
    qDebug() << "MainWindow frame_2" << ui->frame_2->pos() << ui->frame_2->geometry();
    qDebug() << "MainWindow frame_3" << ui->frame_3->pos() << ui->frame_3->geometry();
    qDebug() << "MainWindow centralWidget" << ui->centralWidget->pos() << ui->centralWidget->geometry();
    qDebug() << "MainWindow verticalLayout" << ui->verticalLayout->geometry() ;
    qDebug() << "MainWindow pushButton" << ui->pushButton->pos() << ui->pushButton->geometry();
}
