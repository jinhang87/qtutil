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
        connect(dayTrack, &DayTrack::spliterClicked, this, [=](int, QRect){
            qDebug() << "spliterClicked id = " << id;
            setDayTracksUnSelected(id);
            checkId = id;
        });
    }
    //qDebug() << mapDayTracks;
}

int DayTrackGroup::checkedId() const
{
    return checkId;
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

void DayTrackGroup::setDayTracksUnSelected(int ExceptionalId)
{
    QMapIterator<int, DayTrack *> it(mapDayTracks);
    while (it.hasNext()) {
        it.next();
        DayTrack *dayTrack = it.value();
        if(it.key() != ExceptionalId){
            dayTrack->setSelected(-1);
        }
    }
}
