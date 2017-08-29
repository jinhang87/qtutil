#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSharedPointer>

namespace Ui {
class MainWindow;
}

class DayTrack;
class DayTrackGroup;
class TimeTip;
class WeekPlanCopyablePanel;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void mousePressEvent(QMouseEvent *e);

private slots:
    void on_copytopushbutton_clicked();
    void on_newpushbutton_clicked();
    void on_deletepushbutton_clicked();
    void on_clearpushbutton_clicked();

private:
    void resetCopyWidget();
private:
    Ui::MainWindow *ui;
    DayTrackGroup *dayGroup;
    TimeTip *tip;
    QSharedPointer<WeekPlanCopyablePanel> copyWidget;
};

#endif // MAINWINDOW_H
