#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPointer>

namespace Ui {
class MainWindow;
}
class QThread;
class Worker;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QThread* thread;
    QPointer<Worker> worker;

public slots:
    void handleResult(const QString &parameter);

signals:
    void operate(const QString &parameter);
};

#endif // MAINWINDOW_H
