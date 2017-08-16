#include "sliderbutton.h"
#include <QPainter>
#include <QPaintEvent>
#include <QDebug>

SliderButton::SliderButton(QWidget *parent) : QPushButton(parent)
{
    resize(QSize(12,12));
}

void SliderButton::mousePressEvent(QMouseEvent * event)
{
    pressedPos = event->pos().x();
}

void SliderButton::mouseMoveEvent(QMouseEvent * event)
{
    int changePos = event->pos().x() - pressedPos;
    emit posChanged(changePos);
}

void SliderButton::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    QPainterPath path;
    path.moveTo(0, 6);
    path.lineTo(0, 12);
    path.lineTo(12, 12);
    path.lineTo(12, 0);
    path.lineTo(0, 6);

    //设置无画笔，避免边框出现一条黑线
    painter.setPen(Qt::NoPen);
    //设置画刷
    painter.setBrush(QBrush(QColor(36,169,225), Qt::SolidPattern));
    //绘制背景
    painter.drawPath(path);
    e->accept();//不再向父类传递消息
}
