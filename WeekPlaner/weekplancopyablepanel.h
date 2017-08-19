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

protected:
    bool eventFilter(QObject *watched, QEvent *event);

private:
    Ui::WeekPlanCopyablePanel *ui;
    DayTrackGroup *dayGroup;
    int sourceId;
    QHash<int, bool> hashChecked;
};

#endif // WEEKPLANCOPYABLEPANEL_H
