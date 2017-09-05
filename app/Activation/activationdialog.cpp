#include "activationdialog.h"
#include "ui_activationdialog.h"

ActivationDialog::ActivationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ActivationDialog)
{
    ui->setupUi(this);
}

ActivationDialog::~ActivationDialog()
{
    delete ui;
}
