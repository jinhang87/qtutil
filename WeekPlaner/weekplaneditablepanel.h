#ifndef WEEKPLANEDITABLEPANEL_H
#define WEEKPLANEDITABLEPANEL_H

#include <QWidget>

namespace Ui {
class WeekPlanEditablePanel;
}
class DayTrackGroup;
class TimeTip;
class WeekPlanEditablePanel : public QWidget
{
    Q_OBJECT

public:
    explicit WeekPlanEditablePanel(QWidget *parent = 0);
    ~WeekPlanEditablePanel();

private:
    Ui::WeekPlanEditablePanel *ui;
    DayTrackGroup *dayGroup;
    TimeTip *tip;
};

#endif // WEEKPLANEDITABLEPANEL_H
