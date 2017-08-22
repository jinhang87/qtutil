#include "channelboxwidget.h"
#include "ui_channelboxwidget.h"
#include "channelboxdialog.h"
#include <QDebug>

ChannelBoxWidget::ChannelBoxWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChannelBoxWidget)
{
    ui->setupUi(this);
    m_btnGroupChannelFlag = new QButtonGroup(this);
    m_btnGroupChannelFlag->addButton(ui->radioButton, ChannelBoxDialog::Analog);
    m_btnGroupChannelFlag->addButton(ui->radioButton_2, ChannelBoxDialog::Network);
    setupUi();
}

ChannelBoxWidget::~ChannelBoxWidget()
{
    delete ui;
}

QAbstractItemModel *ChannelBoxWidget::model() const
{
    return m_model;
}

void ChannelBoxWidget::setModel(QAbstractItemModel *model)
{
    m_model = model;
    setupUi();
}

void ChannelBoxWidget::setupUi()
{
    if(!m_model)
        return;

    QLayoutItem *sizeBtn = 0;
    while((sizeBtn = ui->gridLayout->takeAt(0)) != 0){
        ui->gridLayout->widget()->setParent(0);
        delete sizeBtn;
    }
#if 0
    int i = 0;
    for(i = 0; i < m_model->columnCount(); i++){
        QLabel *label = new QLabel(QString::number(i+1), this);
        label->resize(50,50);
        //m_listLabels << label;
        ui->gridLayout->addWidget(label, i/LAEBL_PER_LINE, i%LAEBL_PER_LINE);
    }
#endif
    int row = 0, column = 0, count = 0;
    //for(row = 0; row < m_model->rowCount(); row++){
        for(column = 0; column < m_model->columnCount(); column++){
            QModelIndex index = m_model->index(row, column);
            QString text = m_model->data(index, Qt::DisplayRole).toString();
            bool isChecked = m_model->data(index, Qt::CheckStateRole).toBool();
            QLabel *label = new QLabel(text, this);
            if(isChecked){
                label->setStyleSheet(QString("QLabel{ background: red }"));
            }
            ui->gridLayout->addWidget(label, column/LAEBL_PER_LINE, column%LAEBL_PER_LINE);

#if 0
            if(!text.isEmpty()){
                QRadioButton *radio = new QRadioButton(text, this);
                bool isChecked = m_model->data(index, Qt::CheckStateRole).toBool();
                radio->setChecked(isChecked);
                m_vbox->addWidget(radio, row, column);
                m_btnGroup->addButton(radio, count);
                m_mapBtnsIndex[count] = index;
                count++;
            }
#endif
        }
    //}

}
