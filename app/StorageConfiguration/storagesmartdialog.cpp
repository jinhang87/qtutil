#include "storagesmartdialog.h"
#include "ui_storagesmartdialog.h"

StorageSmartDialog::StorageSmartDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StorageSmartDialog)
{
    ui->setupUi(this);
}

StorageSmartDialog::~StorageSmartDialog()
{
    delete ui;
}
