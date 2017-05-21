#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class EmitData{
public:
    int param1;
    int parma2;
};


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void send(EmitData data);

private:
    void recv(EmitData data);
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
