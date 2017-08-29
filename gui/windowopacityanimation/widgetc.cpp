#include "widgetc.h"
#include "ui_widgetc.h"
#include <QPainter>

WidgetC::WidgetC(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetC)
{
    ui->setupUi(this);
}

WidgetC::~WidgetC()
{
    delete ui;
}

void WidgetC::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.setCompositionMode( QPainter::CompositionMode_Clear );
    p.fillRect( 10, 10, 300, 300, Qt::SolidPattern );
}
