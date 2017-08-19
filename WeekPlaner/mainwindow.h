#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class DayTrack;
class DayTrackGroup;
class TimeTip;

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

    void on_okpushButton_clicked();

    void on_cancelpushButton_clicked();

private:
    Ui::MainWindow *ui;
    DayTrackGroup *dayGroup;
    TimeTip *tip;

    int editWidgetSelectedId;
    DayTrack* editWidgetSelectedDaytrack;
    QList<int> copyWidgetCheckedId;
};

#endif // MAINWINDOW_H
