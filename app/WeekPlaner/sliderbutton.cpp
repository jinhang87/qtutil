#include "sliderbutton.h"
#include <QPainter>
#include <QPaintEvent>
#include <QDebug>

SliderButton::SliderButton(Qt::MouseButton enumButton, QWidget *parent) : QPushButton(parent), m_enumButton(enumButton)
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
    painter.setWindow(0,0,12,12);
    painter.setViewport(0,0,width(), height());

    QPainterPath path;
    if(m_enumButton == Qt::LeftButton){
        path.moveTo(0, 6);
        path.lineTo(0, 12);
        path.lineTo(12, 12);
        path.lineTo(12, 0);
        path.lineTo(0, 6);
    }else{
        path.moveTo(0, 0);
        path.lineTo(0, 12);
        path.lineTo(12, 12);
        path.lineTo(12, 6);
        path.lineTo(0, 0);
    }

    //设置无画笔，避免边框出现一条黑线
    painter.setPen(Qt::NoPen);
    //设置画刷
    painter.setBrush(QBrush(QColor(36,169,225), Qt::SolidPattern));
    //绘制背景
    painter.drawPath(path);
    //不再向父类传递消息
    e->accept();
}

QSize SliderButton::sizeHint() const
{
    return QSize(12,12);
}
