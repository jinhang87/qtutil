#ifndef STORAGEOVERVIEWWIDGET_H
#define STORAGEOVERVIEWWIDGET_H

#include <QWidget>

namespace Ui {
class StorageOverviewWidget;
}
class StorageModel;
class StorageOverviewWidget : public QWidget
{
    Q_OBJECT

public:
    explicit StorageOverviewWidget(QWidget *parent = 0);
    ~StorageOverviewWidget();

private slots:
    void on_smart1_clicked();

protected:
    bool eventFilter(QObject *watched, QEvent *event);

private:
    void setupUi();
    Ui::StorageOverviewWidget *ui;
    StorageModel* m_model;
};

#endif // STORAGEOVERVIEWWIDGET_H
