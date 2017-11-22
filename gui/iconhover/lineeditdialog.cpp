#include "lineeditdialog.h"
#include "ui_lineeditdialog.h"

LineEditDialog::LineEditDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LineEditDialog)
{
    ui->setupUi(this);
    setStyleSheet("QLineEdit { border: none; background : transparent }");
}

LineEditDialog::~LineEditDialog()
{
    delete ui;
}
