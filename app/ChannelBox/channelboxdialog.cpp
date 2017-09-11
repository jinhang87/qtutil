#include "channelboxdialog.h"
#include "ui_channelboxdialog.h"
#include "channelboxmodel.h"
#include <QDebug>

ChannelBoxDialog::ChannelBoxDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChannelBoxDialog)
{
    ui->setupUi(this);
    setStyleSheet("QLabel{font-size: 24px ; color: #848484 }"
                  "QPushButton, QRadioButton{font-size: 24px ; color: #dddddd; background: #191919}"
                  "QDialog{background: #646464;}");
}

ChannelBoxDialog::~ChannelBoxDialog()
{
    delete ui;
}

void ChannelBoxDialog::setSelectedMode(const ChannelBoxWidget::SelectedMode &selectedMode)
{
    ui->widget->setSelectedMode(selectedMode);
}

void ChannelBoxDialog::accept()
{
    emit accepted(ui->widget->checkedRoles());
    QDialog::accept();
}

