#include "coveragepaintdialog.h"
#include "ui_coveragepaintdialog.h"
#include <QDebug>

CoveragePaintDialog::CoveragePaintDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CoveragePaintDialog)
{
    ui->setupUi(this);
    setStyleSheet("QFrame{ background : red}");
    qDebug()<<ui->widget->rect();
}

CoveragePaintDialog::~CoveragePaintDialog()
{
    delete ui;
}

void CoveragePaintDialog::paintEvent(QPaintEvent *event)
{
#if 0
    QPainter p(this);
    p.setCompositionMode(QPainter::CompositionMode_Clear);
    QPoint point = ui->widget->mapTo(this, ui->widget->rect().topLeft());
    QRect clearRect(point, ui->widget->rect().size());
    p.fillRect(clearRect ,Qt::SolidPattern);
#endif

    QDialog::paintEvent(event);
}

