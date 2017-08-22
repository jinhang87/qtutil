#include "channelboxdialog.h"
#include "ui_channelboxdialog.h"
#include "channelboxmodel.h"

ChannelBoxDialog::ChannelBoxDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChannelBoxDialog)
{
    ui->setupUi(this);
    m_model.reset(new ChannelBoxModel());
    m_model->setMaxAnalogChannelNum(32);
    m_model->setMaxNetworkChannelNum(32);
    ui->widget->setModel(m_model.data());
}

ChannelBoxDialog::~ChannelBoxDialog()
{
    delete ui;
}

void ChannelBoxDialog::accept()
{
    QMultiHash<ChannelFlag, int> hash;
    emit accepted(hash);
    QDialog::accept();
}

ChannelBoxDialog::Mode ChannelBoxDialog::mode() const
{
    return m_mode;
}

void ChannelBoxDialog::setMode(const Mode &mode)
{
    m_mode = mode;
}
