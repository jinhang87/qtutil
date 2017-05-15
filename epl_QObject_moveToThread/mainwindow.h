#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void sendopeatesignal();
    Ui::MainWindow *ui;
    QThread* thread;
    Worker* worker;

public slots:
    void handleResult(const QString &parameter);

signals:
    void operate(const QString &parameter);
};

#endif // MAINWINDOW_H
