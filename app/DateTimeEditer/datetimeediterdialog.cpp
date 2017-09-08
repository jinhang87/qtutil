#include "datetimeediterdialog.h"
#include "ui_datetimeediterdialog.h"

DateTimeEditerDialog::DateTimeEditerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DateTimeEditerDialog)
{
    ui->setupUi(this);
    setStyleSheet(
                "QTimeEdit::up-button,QSpinBox::up-button { subcontrol-position:right; width: 32px; height: 32px;}"
                "QTimeEdit::down-button,QSpinBox::down-button { subcontrol-position:left; width: 32px; height: 32px;}"
                );
}

DateTimeEditerDialog::~DateTimeEditerDialog()
{
    delete ui;
}
