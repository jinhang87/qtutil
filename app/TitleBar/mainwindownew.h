#ifndef MAINWINDOWNEW_H
#define MAINWINDOWNEW_H

#include <QMainWindow>

namespace Ui {
class MainWindowNew;
}

class MainWindowNew : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowNew(QWidget *parent = 0);
    ~MainWindowNew();

private:
    Ui::MainWindowNew *ui;
};

#endif // MAINWINDOWNEW_H
