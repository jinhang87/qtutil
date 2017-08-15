#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

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
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    DayTrackGroup *dayGroup;
    TimeTip *tip;
};

#endif // MAINWINDOW_H
