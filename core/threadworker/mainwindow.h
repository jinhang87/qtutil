#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPointer>
#include <QSharedPointer>
#include <QProgressDialog>

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
#ifdef USE_QPOINTER
    QPointer<Worker> worker;
#else
    Worker* worker;
#endif
public slots:
    void handleResult(const QString &parameter);

signals:
    void operate(const QString &parameter);

private slots:
    void on_pushButtonInvoke_clicked();

private:
    QSharedPointer<QProgressDialog> m_dialogWait;
};

#endif // MAINWINDOW_H
