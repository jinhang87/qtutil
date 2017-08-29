#include "datetimeediterwidget.h"
#include "ui_datetimeediterwidget.h"
#include "datetimeeditermodel.h"
#include <QDebug>

DateTimeEditerWidget::DateTimeEditerWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DateTimeEditerWidget)
{
    ui->setupUi(this);
    m_model = QSharedPointer<DateTimeEditerModel>(new DateTimeEditerModel());
    m_model->setMaxNum(32);

    setupUi();
}

DateTimeEditerWidget::~DateTimeEditerWidget()
{
    delete ui;
}

bool DateTimeEditerWidget::eventFilter(QObject *watched, QEvent *event)
{
    QLabel* label = qobject_cast<QLabel*>(watched);
    if(label && m_hashWatchedLabels.contains(qobject_cast<QLabel*>(watched))){
        if(event->type() == QEvent::MouseButtonRelease){
            QModelIndex index = m_hashWatchedLabels[label];
            qDebug() << "eventFilter " << index;
            m_model->clearChecked();
            m_model->setData(index, true, Qt::CheckStateRole);
            setupUi();
            return true;
        }
    }

    return QWidget::eventFilter(watched, event);
}

void DateTimeEditerWidget::setupUi()
{
    QSharedPointer<DateTimeEditerModel> model = m_model;
    if(!model)
        return;
    qDebug() << "setupUi";

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
