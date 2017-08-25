#include "channelboxwidget.h"
#include "ui_channelboxwidget.h"
#include "channelboxmodel.h"
#include <QDebug>
#include <QPaintEvent>

ChannelBoxWidget::ChannelBoxWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChannelBoxWidget)
{
    ui->setupUi(this);
    m_hashModel[AnalogRole] = QSharedPointer<ChannelBoxModel>(new ChannelBoxModel());
    m_hashModel[AnalogRole]->setMaxNum(32);
    connect(m_hashModel[AnalogRole].data(), &ChannelBoxModel::modelReset, this , [=](){
        setupUi(AnalogRole);
    });
    m_hashModel[NetworkRole] = QSharedPointer<ChannelBoxModel>(new ChannelBoxModel());
    m_hashModel[NetworkRole]->setMaxNum(16);
    connect(m_hashModel[NetworkRole].data(), &ChannelBoxModel::modelReset, this , [=](){
        setupUi(NetworkRole);
    });
    m_ChannelButtonGroup = new QButtonGroup(this);
    m_ChannelButtonGroup->addButton(ui->radioButton, AnalogRole);
    m_ChannelButtonGroup->addButton(ui->radioButton_2, NetworkRole);
    connect(m_ChannelButtonGroup, static_cast<void (QButtonGroup::*)(int)>(&QButtonGroup::buttonClicked), this, [=](int id){
        setupUi((ChannelButtonRole)id);
    });
    setupUi(AnalogRole);
}

ChannelBoxWidget::~ChannelBoxWidget()
{
    delete ui;
}

bool ChannelBoxWidget::eventFilter(QObject *watched, QEvent *event)
{
    QLabel* label = qobject_cast<QLabel*>(watched);
    if(label && m_hashWatchedLabels.contains(qobject_cast<QLabel*>(watched))){
        if(event->type() == QEvent::MouseButtonRelease){
            QModelIndex index = m_hashWatchedLabels[label];
            if(m_ChannelButtonGroup->checkedId() != -1){
                ChannelButtonRole role = (ChannelButtonRole)m_ChannelButtonGroup->checkedId();
                qDebug() << "eventFilter role " << role << index;
                QSharedPointer<ChannelBoxModel> model = m_hashModel[role];
                model->setData(index, true, Qt::CheckStateRole);
                setupUi(role);
                return true;
            }
        }
    }

    //    if(-1 != (id = dayGroup->id(qobject_cast<QLabel*>(watched))) ){
    //        if(event->type() == QEvent::MouseButtonRelease){
    //            if(!hashChecked[id]){
    //                dayGroup->copyto(sourceId, id);
    //                hashChecked[id] = true;
    //                emit checkedIdChanged(id, true);
    //            }else{
    //                dayGroup->dayTrack(id)->clearSpliters();
    //                hashChecked[id] = false;
    //                emit checkedIdChanged(id, false);
    //            }
    //            return true;
    //        }
    //    }

    return QWidget::eventFilter(watched, event);
}

void ChannelBoxWidget::paintEvent(QPaintEvent *e)
{
    QWidget::paintEvent(e);
}

void ChannelBoxWidget::setupUi(ChannelButtonRole role)
{
    QSharedPointer<ChannelBoxModel> model = m_hashModel[role];
    if(!model)
        return;
    qDebug() << "setupUi" << role;

    QGridLayout *layout = ui->gridLayout;
    QLayoutItem *child = 0;
    while((child = layout->takeAt(0)) != 0){
        child->widget()->setParent(0);
        delete child;
    }

    int row = 0;
    for(row = 0; row < model->rowCount(); row++){
        QModelIndex index = model->index(row);
        QString text = model->data(index, Qt::DisplayRole).toString();
        bool isChecked = model->data(index, Qt::CheckStateRole).toBool();
        QLabel *label = new QLabel(text, this);
        if(isChecked){
            label->setStyleSheet(QString("QLabel{ background: red }"));
        }
        label->installEventFilter(this);
        m_hashWatchedLabels[label] = index;
        layout->addWidget(label, row/LAEBL_PER_LINE, row%LAEBL_PER_LINE);
    }

}
