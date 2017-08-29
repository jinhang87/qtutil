#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}
class QTranslator;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void changeEvent(QEvent *event) override;
private:
    Ui::MainWindow *ui;
    void changeTranslator(const QString &file);
    QTranslator* m_tras;
};

#endif // MAINWINDOW_H
