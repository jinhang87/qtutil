#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}
class QLabel;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bool event(QEvent *event) override;

private slots:
    void on_radioButton_clicked();

private:
    Ui::MainWindow *ui;
    QLabel *tips;
};

#endif // MAINWINDOW_H
