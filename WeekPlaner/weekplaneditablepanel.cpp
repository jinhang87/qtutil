#include "weekplaneditablepanel.h"
#include "ui_weekplaneditablepanel.h"
#include "daytrackgroup.h"
#include "timetip.h"

WeekPlanEditablePanel::WeekPlanEditablePanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WeekPlanEditablePanel)
{
    ui->setupUi(this);
    dayGroup = new DayTrackGroup(this);
    dayGroup->addDayTrack(ui->frame, 1);
    dayGroup->addDayTrack(ui->frame_2, 2);
    dayGroup->addDayTrack(ui->frame_3, 3);
    dayGroup->addDayTrack(ui->frame_4, 4);
    dayGroup->addDayTrack(ui->frame_5, 5);
    dayGroup->addDayTrack(ui->frame_6, 6);
    dayGroup->addDayTrack(ui->frame_7, 7);
    tip = new TimeTip(this);
    tip->hide();

    connect(dayGroup, &DayTrackGroup::DayTrackClicked, this, [=](int id, QRect rect){
        DayTrack *dayTrack = dayGroup->dayTrack(id);
        QPoint p = dayTrack->mapTo(this, rect.topLeft());
        tip->setCentralRect(QRect(p, rect.size()));
        tip->setDaytrack(dayTrack);
        SegmentSpliter spliter = dayTrack->rectToSpliter(rect);
        QString text = QString("%1~%2").arg(spliter.start).arg(spliter.end);
        tip->setText(text);
        tip->show();
    });


    connect(dayGroup, &DayTrackGroup::DayTrackOutSideClicked, this, [=](int){
        tip->hide();
    });
}

WeekPlanEditablePanel::~WeekPlanEditablePanel()
{
    delete ui;
}
