#include "dialog.h"
#include "ui_dialog.h"
#include "faderwidget.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    m_fader = new FaderWidget(this);
    m_fader->start();
}

Dialog::~Dialog()
{
    delete ui;
}
