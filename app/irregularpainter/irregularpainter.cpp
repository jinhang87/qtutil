#include "irregularpainter.h"
#include <QPainter>
#include <QPaintEvent>

IrregularPainter::IrregularPainter(QWidget *parent) : QWidget(parent)
{

}

void IrregularPainter::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    qreal radius = width()/8.5;
    qreal border = 4;
    QPen pen(Qt::black, border);
    painter.setPen(pen);

    QPainterPath path;
    path.moveTo(width()/2-radius-border, radius+border);
    path.lineTo(border, radius+border);
    path.lineTo(border, height()-border);
    path.lineTo(width()-border, height()-border);
    path.lineTo(width()-border, radius+border);
    path.lineTo(width()/2+radius+border, radius+border);
    painter.drawPath(path);

    QRectF rectangle(width()/2-radius, border, radius*2, radius*2);
    painter.drawEllipse(rectangle);

    event->accept();
}
