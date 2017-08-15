#ifndef DAYTRACKGROUP_H
#define DAYTRACKGROUP_H

#include <QObject>
#include <QMap>

class DayTrack;
class DayTrackGroup : public QObject
{
    Q_OBJECT
public:
    explicit DayTrackGroup(QObject *parent = 0);
    void addDayTrack(DayTrack *dayTrack, int id = -1);
    int checkedId() const;
    int id(DayTrack *dayTrack) const;


signals:

public slots:
    //void onDayTrackSpliterClicked(int index, QRect rect);

private:
    void setDayTracksUnSelected(int ExceptionalId);
    QMap<int, DayTrack *> mapDayTracks;
    int checkId;
};

#endif // DAYTRACKGROUP_H
