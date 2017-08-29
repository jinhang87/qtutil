#include "datetimeediterdialog.h"
#include "ui_datetimeediterdialog.h"

DateTimeEditerDialog::DateTimeEditerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DateTimeEditerDialog)
{
    ui->setupUi(this);
}

DateTimeEditerDialog::~DateTimeEditerDialog()
{
    delete ui;
}
