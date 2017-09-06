#include "storageoverviewwidget.h"
#include "ui_storageoverviewwidget.h"
#include "storagesmartdialog.h"
#include "storagemodel.h"

#include <QDebug>

StorageOverviewWidget::StorageOverviewWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StorageOverviewWidget)
{
    ui->setupUi(this);
    ui->frame->installEventFilter(this);
    ui->frame_2->installEventFilter(this);
    ui->frame_3->installEventFilter(this);
    ui->frame_4->installEventFilter(this);
    m_model = new StorageModel(this);
    setupUi();
}

StorageOverviewWidget::~StorageOverviewWidget()
{
    delete ui;
}

void StorageOverviewWidget::on_smart1_clicked()
{
    StorageSmartDialog d;
    d.show();
    d.exec();
}

bool StorageOverviewWidget::eventFilter(QObject *watched, QEvent *event)
{
    if(qobject_cast<QFrame*>(watched)){
        if(event->type() == QEvent::MouseButtonRelease){
            qDebug()<<"mouse press";
        }
    }
    return QWidget::eventFilter(watched, event);
}

void StorageOverviewWidget::setupUi()
{
    if(!m_model){
        return;
    }
    ui->capacity1->setText(tr("HD1 %1G/%2G").arg(500).arg(1000));
}
