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

QList<DayTrack *> DayTrackGroup::dayTracks() const
{
   QList<DayTrack *> list;
   QMapIterator<int, DayTrack *> it(mapDayTracks);
   while (it.hasNext()) {
       it.next();
       list << it.value();
   }
   return list;
}

bool DayTrackGroup::copyto(int source, int destination)
{
    DayTrack *dayTrackDestination = dayTrack(destination);
    DayTrack *dayTrackSource = dayTrack(source);

    if(dayTrackSource && dayTrackDestination){
        dayTrackDestination->setSpliters(dayTrackSource->getSpliters());
        return true;
    }else{
        return false;
    }
}

bool DayTrackGroup::copyto(const DayTrack *source, int destination)
{
    DayTrack *dayTrackDestination = dayTrack(destination);
    if(source && dayTrackDestination){
        dayTrackDestination->setSpliters(source->getSpliters());
        return true;
    }else{
        return false;
    }
}

void DayTrackGroup::clear()
{
    QMapIterator<int, DayTrack *> it(mapDayTracks);
    while (it.hasNext()) {
        it.next();
        DayTrack *dayTrack = it.value();
        dayTrack->clearSpliters();
    }
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
