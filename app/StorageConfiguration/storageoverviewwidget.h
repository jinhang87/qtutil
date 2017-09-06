#ifndef STORAGEOVERVIEWWIDGET_H
#define STORAGEOVERVIEWWIDGET_H

#include <QWidget>

namespace Ui {
class StorageOverviewWidget;
}

class StorageOverviewWidget : public QWidget
{
    Q_OBJECT

public:
    explicit StorageOverviewWidget(QWidget *parent = 0);
    ~StorageOverviewWidget();

private:
    Ui::StorageOverviewWidget *ui;
};

#endif // STORAGEOVERVIEWWIDGET_H
