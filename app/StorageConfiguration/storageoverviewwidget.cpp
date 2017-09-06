#include "storageoverviewwidget.h"
#include "ui_storageoverviewwidget.h"

StorageOverviewWidget::StorageOverviewWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StorageOverviewWidget)
{
    ui->setupUi(this);
}

StorageOverviewWidget::~StorageOverviewWidget()
{
    delete ui;
}
