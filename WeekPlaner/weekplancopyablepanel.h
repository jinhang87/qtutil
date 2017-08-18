#ifndef WEEKPLANCOPYABLEPANEL_H
#define WEEKPLANCOPYABLEPANEL_H

#include <QWidget>

namespace Ui {
class WeekPlanCopyablePanel;
}
class DayTrackGroup;
class TimeTip;
class WeekPlanCopyablePanel : public QWidget
{
    Q_OBJECT

public:
    explicit WeekPlanCopyablePanel(QWidget *parent = 0);
    ~WeekPlanCopyablePanel();

    int getSourceId() const;
    void setSourceId(int value);

private:
    Ui::WeekPlanCopyablePanel *ui;
    DayTrackGroup *dayGroup;
    int sourceId;
};

#endif // WEEKPLANCOPYABLEPANEL_H
