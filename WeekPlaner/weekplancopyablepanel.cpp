#include "weekplancopyablepanel.h"
#include "ui_weekplancopyablepanel.h"
#include "daytrackgroup.h"
#include "timetip.h"
#include <QDebug>

WeekPlanCopyablePanel::WeekPlanCopyablePanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WeekPlanCopyablePanel), sourceId(0)
{
    ui->setupUi(this);

    //for test
    sourceId = 1;

    QList<SegmentSpliter> spliters;
    SegmentSpliter spliter;
    spliter.start = (qreal)1/24;
    spliter.end = (qreal)3/24;
    spliters << spliter;

    spliter.start = (qreal)5/24;
    spliter.end = (qreal)8/24;
    spliters << spliter;
    ui->frame->setSpliters(spliters);

    spliter.start = (qreal)11/24;
    spliter.end = (qreal)24/24;
    spliters << spliter;
    ui->frame_2->setSpliters(spliters);

    dayGroup = new DayTrackGroup(this);
    dayGroup->addDayTrack(ui->frame, 1);
    dayGroup->addDayTrack(ui->frame_2, 2);
    dayGroup->addDayTrack(ui->frame_3, 3);
    dayGroup->addDayTrack(ui->frame_4, 4);
    dayGroup->addDayTrack(ui->frame_5, 5);
    dayGroup->addDayTrack(ui->frame_6, 6);
    dayGroup->addDayTrack(ui->frame_7, 7);

    connect(dayGroup, &DayTrackGroup::DayTrackClicked, this, [=](int id, QRect){
        if(id == sourceId){
            return;
        }
        DayTrack *dayTrack = dayGroup->dayTrack(id);
        dayTrack->clearSpliters();
    });

    connect(dayGroup, &DayTrackGroup::DayTrackOutSideClicked, this, [=](int id){
        qDebug() << "DayTrackGroup::DayTrackOutSideClicked" << id;
        DayTrack *dayTrackDestination = dayGroup->dayTrack(id);
        DayTrack *dayTrackSource = dayGroup->dayTrack(sourceId);
        if(dayTrackSource && dayTrackDestination){
            dayTrackDestination->setSpliters(dayTrackSource->getSpliters());
        }

    });

}

WeekPlanCopyablePanel::~WeekPlanCopyablePanel()
{
    delete ui;
}

int WeekPlanCopyablePanel::getSourceId() const
{
    return sourceId;
}

void WeekPlanCopyablePanel::setSourceId(int value)
{
    sourceId = value;
}
