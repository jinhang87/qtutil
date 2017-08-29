#ifndef WEEKPLANCOPYABLEPANEL_H
#define WEEKPLANCOPYABLEPANEL_H

#include <QWidget>

namespace Ui {
class WeekPlanCopyablePanel;
}
class DayTrack;
class DayTrackGroup;
class TimeTip;
class WeekPlanCopyablePanel : public QWidget
{
    Q_OBJECT

public:
    explicit WeekPlanCopyablePanel(QWidget *parent = 0);
    ~WeekPlanCopyablePanel();
    int getSourceId() const;
    void setSourceId(int value, const DayTrack *daytrack);
    QList<int> checkedId() const;

protected:
    bool eventFilter(QObject *watched, QEvent *event);

signals:
    void checkedIdChanged(int id, bool bChecked);

private:
    Ui::WeekPlanCopyablePanel *ui;
    DayTrackGroup *dayGroup;
    int sourceId;
    QHash<int, bool> hashChecked;
};

#endif // WEEKPLANCOPYABLEPANEL_H
