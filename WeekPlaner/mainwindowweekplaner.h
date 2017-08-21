#ifndef MAINWINDOWWEEKPLANER_H
#define MAINWINDOWWEEKPLANER_H

#include <QMainWindow>

namespace Ui {
class MainWindowWeekPlaner;
}

class MainWindowWeekPlaner : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowWeekPlaner(QWidget *parent = 0);
    ~MainWindowWeekPlaner();

private:
    Ui::MainWindowWeekPlaner *ui;
};

#endif // MAINWINDOWWEEKPLANER_H
