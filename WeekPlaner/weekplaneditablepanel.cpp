#include "weekplaneditablepanel.h"
#include "ui_weekplaneditablepanel.h"
#include "daytrackgroup.h"
#include "timetip.h"
#include <QDebug>

WeekPlanEditablePanel::WeekPlanEditablePanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WeekPlanEditablePanel),
    selectedId(-1)
{
    ui->setupUi(this);

#if 1 //for test
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
    ui->frame_3->setSpliters(spliters);
#endif

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

    connect(dayGroup, &DayTrackGroup::DayTrackClicked, this, [&](int id, QRect rect){
        DayTrack *dayTrack = dayGroup->dayTrack(id);
        QPoint p = dayTrack->mapTo(this, rect.topLeft());
        tip->setCentralRect(QRect(p, rect.size()));
        tip->setDaytrack(dayTrack);
        SegmentSpliter spliter = dayTrack->rectToSpliter(rect);
        QString text = QString("%1~%2").arg(spliter.start).arg(spliter.end);
        tip->setText(text);
        tip->show();
        selectedId = id;
    });


    connect(dayGroup, &DayTrackGroup::DayTrackOutSideClicked, this, [=](int){
        tip->hide();
    });
}

WeekPlanEditablePanel::~WeekPlanEditablePanel()
{
    delete ui;
}

void WeekPlanEditablePanel::setCopyableId(const QList<int> &listId)
{
    QListIterator<int> it(listId);
    while (it.hasNext()) {
        int id = it.next();
        dayGroup->copyto(selectedId, id);
    }
}

int WeekPlanEditablePanel::getSelectedId() const
{
    return selectedId;
}

DayTrack* WeekPlanEditablePanel::getSelectedDayTrack() const
{
    if(-1 != selectedId){
        return dayGroup->dayTrack(selectedId);
    }else{
        return nullptr;
    }
}

DayTrackGroup *WeekPlanEditablePanel::getDayGroup() const
{
    return dayGroup;
}
