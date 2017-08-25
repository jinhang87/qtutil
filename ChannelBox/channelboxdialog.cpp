#include "channelboxdialog.h"
#include "ui_channelboxdialog.h"
#include "channelboxmodel.h"

ChannelBoxDialog::ChannelBoxDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChannelBoxDialog)
{
    ui->setupUi(this);
}

ChannelBoxDialog::~ChannelBoxDialog()
{
    delete ui;
}

void ChannelBoxDialog::accept()
{
    //emit accepted(m_model->hashChecked());
    QDialog::accept();
}

