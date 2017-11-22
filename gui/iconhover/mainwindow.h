#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButtonImage_clicked();

    void on_pushButtonLabelImage_clicked();

    void on_pushButtonWidgetImage_clicked();

    void on_pushButtonLineEdit_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
