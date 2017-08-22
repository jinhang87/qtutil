#include "channelboxwidget.h"
#include "ui_channelboxwidget.h"
#include "channelboxdialog.h"
#include <QDebug>
#include <QPaintEvent>

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

bool ChannelBoxWidget::eventFilter(QObject *watched, QEvent *event)
{
#if 0
    int id = -1;
    if(-1 != (id = dayGroup->id(qobject_cast<DayTrack*>(watched))) ){
        if(event->type() == QEvent::MouseButtonRelease){
            if(!hashChecked[id]){
                dayGroup->copyto(sourceId, id);
                hashChecked[id] = true;
                emit checkedIdChanged(id, true);
            }else{
                dayGroup->dayTrack(id)->clearSpliters();
                hashChecked[id] = false;
                emit checkedIdChanged(id, false);
            }
            return true;
        }
    }
#endif
    return QWidget::eventFilter(watched, event);
}

void ChannelBoxWidget::paintEvent(QPaintEvent *e)
{
    QWidget::paintEvent(e);
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

    int row = 0, column = 0, count = 0;
    for(column = 0; column < m_model->columnCount(); column++){
        QModelIndex index = m_model->index(row, column);
        QString text = m_model->data(index, Qt::DisplayRole).toString();
        bool isChecked = m_model->data(index, Qt::CheckStateRole).toBool();
        QLabel *label = new QLabel(text, this);
        if(isChecked){
            label->setStyleSheet(QString("QLabel{ background: red }"));
        }
        label->installEventFilter(this);
        ui->gridLayout->addWidget(label, column/LAEBL_PER_LINE, column%LAEBL_PER_LINE);
    }
}
