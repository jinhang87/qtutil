#include "daytrackgroup.h"
#include "daytrack.h"
#include <QDebug>

DayTrackGroup::DayTrackGroup(QObject *parent) : QObject(parent), checkId(-1)
{

}

void DayTrackGroup::addDayTrack(DayTrack *dayTrack, int id)
{
    if(dayTrack){
        mapDayTracks[id] = dayTrack;
        connect(dayTrack, &DayTrack::spliterClicked, this, [=](int, QRect rect){
            setDayTracksUnSelected(id);
            checkId = id;
            emit DayTrackClicked(id, rect);
        });
        connect(dayTrack, &DayTrack::spliterOutsideClicked, this, [=](){
            setDayTracksUnSelected();
            checkId = -1;
            emit DayTrackOutSideClicked(id);
        });
    }
}

int DayTrackGroup::checkedId() const
{
    return checkId;
}

DayTrack *DayTrackGroup::dayTrack(int id) const
{
    return mapDayTracks[id];
}

int DayTrackGroup::id(DayTrack *dayTrack) const
{
    if(!dayTrack){
        return -1;
    }
    QMapIterator<int, DayTrack *> it(mapDayTracks);
    int id = -1;
    while (it.hasNext()) {
        it.next();
        if(it.value() == dayTrack){
            id = it.key();
            break;
        }
    }

    return id;
}

void DayTrackGroup::setDayTracksUnSelected(int exceptionalId)
{
    QMapIterator<int, DayTrack *> it(mapDayTracks);
    while (it.hasNext()) {
        it.next();
        DayTrack *dayTrack = it.value();
        if(it.key() != exceptionalId){
            dayTrack->setSelected(-1);
        }
    }
}
