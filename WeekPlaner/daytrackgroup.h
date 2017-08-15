#ifndef DAYTRACKGROUP_H
#define DAYTRACKGROUP_H

#include <QObject>
#include <QMap>
#include <QRect>

class DayTrack;
class DayTrackGroup : public QObject
{
    Q_OBJECT
public:
    explicit DayTrackGroup(QObject *parent = 0);
    void addDayTrack(DayTrack *dayTrack, int id = -1);
    int checkedId() const;

    DayTrack *dayTrack(int id) const;
    int id(DayTrack *dayTrack) const;

signals:
    void DayTrackClicked(int, QRect);
    void DayTrackOutSideClicked();

public slots:

private:
    void setDayTracksUnSelected(int exceptionalId = -1);
    QMap<int, DayTrack *> mapDayTracks;
    int checkId;
};

#endif // DAYTRACKGROUP_H
