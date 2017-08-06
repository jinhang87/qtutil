#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>
#include <QSharedPointer>
#include <QItemDelegate>

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
    void on_pushButton_clicked();

    void on_listView_indexesMoved(const QModelIndexList &indexes);

    void on_listView_pressed(const QModelIndex &index);

    void on_pushButton_2_clicked();

    void on_listView_clicked(const QModelIndex &index);

private:
    int getDisplayRowsCounts();

private:
    Ui::MainWindow *ui;
    QSharedPointer<QStringListModel> model;
    QSharedPointer<QItemDelegate> delegate;
};

#endif // MAINWINDOW_H
