#include "coveragecontroldialog.h"
#include "ui_coveragecontroldialog.h"
#include "coveragepaintdialog.h"
#include <QPainter>
#include <QDebug>

CoverageControlDialog::CoverageControlDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CoverageControlDialog)
{
    ui->setupUi(this);
    setStyleSheet("QFrame{ background : red}");
}

CoverageControlDialog::~CoverageControlDialog()
{
    delete ui;
}

void CoverageControlDialog::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.setCompositionMode(QPainter::CompositionMode_Clear);
    QPoint point = ui->widget->mapTo(this, ui->widget->rect().topLeft());
    QRect clearRect(point, ui->widget->rect().size());
    p.fillRect(clearRect ,Qt::SolidPattern);
    QDialog::paintEvent(event);
}

void CoverageControlDialog::on_pushButtonNew_clicked()
{
    this->hide();
    CoveragePaintDialog d;
    d.exec();
    this->show();
}
