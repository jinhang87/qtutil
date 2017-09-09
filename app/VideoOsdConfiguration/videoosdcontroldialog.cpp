#include "videoosdcontroldialog.h"
#include "ui_videoosdcontroldialog.h"

VideoOsdControlDialog::VideoOsdControlDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VideoOsdControlDialog)
{
    ui->setupUi(this);
}

VideoOsdControlDialog::~VideoOsdControlDialog()
{
    delete ui;
}
