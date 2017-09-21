#include "circlewidget.h"
#include <QPainter>

CircleWidget::CircleWidget(QWidget *parent) : QWidget(parent)
{

}

void CircleWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setWindow(0,0,100,100);
    painter.setViewport(0,0,width(),height());

    QPen pen(Qt::black, 2);
    painter.setPen(pen);

    QRectF rectangle(0, 0, 100, 100);
    painter.drawEllipse(rectangle);

}

QSize CircleWidget::sizeHint() const
{
    return QSize(44,44);
}
