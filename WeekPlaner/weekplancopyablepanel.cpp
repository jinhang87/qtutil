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
    dayGroup = new DayTrackGroup(this);
    dayGroup->addDayTrack(ui->frame, 1);
    dayGroup->addDayTrack(ui->frame_2, 2);
    dayGroup->addDayTrack(ui->frame_3, 3);
    dayGroup->addDayTrack(ui->frame_4, 4);
    dayGroup->addDayTrack(ui->frame_5, 5);
    dayGroup->addDayTrack(ui->frame_6, 6);
    dayGroup->addDayTrack(ui->frame_7, 7);
    ui->frame->installEventFilter(this);
    ui->frame_2->installEventFilter(this);
    ui->frame_3->installEventFilter(this);
    ui->frame_4->installEventFilter(this);
    ui->frame_5->installEventFilter(this);
    ui->frame_6->installEventFilter(this);
    ui->frame_7->installEventFilter(this);

    int i = 1;
    for(i = 1; i <= 7; i++){
        hashChecked[1] = false;
    }
}

WeekPlanCopyablePanel::~WeekPlanCopyablePanel()
{
    delete ui;
}

int WeekPlanCopyablePanel::getSourceId() const
{
    return sourceId;
}

void WeekPlanCopyablePanel::setSourceId(int id, const DayTrack* daytrack)
{
    if(daytrack){
        sourceId = id;
        dayGroup->copyto(daytrack, id);
    }
}

QList<int> WeekPlanCopyablePanel::checkedId() const
{
    QList<int> list;
    QHashIterator<int, bool> it(hashChecked);
    while (it.hasNext()) {
        it.next();
        if(it.value()){
            list<<it.key();
        }
    }
    return list;
}

void WeekPlanCopyablePanel::clear()
{
    sourceId = -1;
    dayGroup->clear();
}

bool WeekPlanCopyablePanel::eventFilter(QObject *watched, QEvent *event)
{
    int id = -1;
    if(-1 != (id = dayGroup->id(qobject_cast<DayTrack*>(watched))) ){
        if(id == sourceId){
            return false;
        }
        if(event->type() == QEvent::MouseButtonRelease){
            if(!hashChecked[id]){
                dayGroup->copyto(sourceId, id);
                hashChecked[id] = true;
                emit checkedIdChanged(id, true);
            }else{
                dayGroup->dayTrack(id)->clearSpliters();
                hashChecked[id] = false;
                emit checkedIdChanged(id, false);
            }
            return true;
        }
    }
    return QWidget::eventFilter(watched, event);
}
