#ifndef WEEKPLANEDITABLEPANEL_H
#define WEEKPLANEDITABLEPANEL_H

#include <QWidget>

namespace Ui {
class WeekPlanEditablePanel;
}
class DayTrack;
class DayTrackGroup;
class TimeTip;
class WeekPlanEditablePanel : public QWidget
{
    Q_OBJECT

public:
    explicit WeekPlanEditablePanel(QWidget *parent = 0);
    ~WeekPlanEditablePanel();
    void setCopyableId(const QList<int>& listId);
    int getSelectedId() const;
    DayTrack *getSelectedDayTrack() const;
    DayTrackGroup *getDayGroup() const;

signals:
    void selectedIdChanged(int selectedId);
    void selectedSignal();
    void unSelectedSignal();

private:
    Ui::WeekPlanEditablePanel *ui;
    DayTrackGroup *dayGroup;
    TimeTip *tip;
    int selectedId;
};

#endif // WEEKPLANEDITABLEPANEL_H
