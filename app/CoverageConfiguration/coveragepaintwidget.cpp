#include "coveragepaintwidget.h"
#include <QPainter>
#include <QDebug>
#include <QMouseEvent>

CoveragePaintWidget::CoveragePaintWidget(QWidget *parent) : QWidget(parent)
{

}

void CoveragePaintWidget::paintEvent(QPaintEvent *event)
{
    qDebug()<<rect();
    QPainter p(this);
    p.setCompositionMode(QPainter::CompositionMode_Clear);
    p.fillRect(rect() ,Qt::SolidPattern);
    p.end();

    if(m_bReflush){
        m_buffer = m_TempBuffer = QPixmap(size());
        m_bReflush = false;
    }

    p.begin(&m_TempBuffer);
    if(m_bStart && m_bEnd){
        p.setPen(QPen(Qt::green, 2));
        p.setBrush(Qt::blue);
        int x = m_startPonit.x();
        int y = m_startPonit.y();
        int w = m_endPoint.x()-m_startPonit.x();
        int h = m_endPoint.y()-m_startPonit.y();
        p.drawRect(x, y, w, h);
    }
    if(m_bStart){
        p.setPen(QPen(Qt::green, 2));
        p.setBrush(Qt::green);
        p.drawEllipse(m_startPonit, 10, 10);
    }
    if(m_bEnd){
        p.setPen(QPen(Qt::green, 2));
        p.setBrush(Qt::green);
        p.drawEllipse(m_endPoint, 10, 10);
    }
    p.end();

    p.begin(this);
    p.drawPixmap(0,0,m_TempBuffer);
    if(!m_isDrawing){
        m_buffer = m_TempBuffer;
    }
    p.end();

    QWidget::paintEvent(event);
}

void CoveragePaintWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        m_startPonit = event->pos();
        m_isDrawing = true;
        m_bStart = true;
        m_bEnd = false;
        m_bReflush = true;
        update();
    }
}

void CoveragePaintWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        m_endPoint = event->pos();
        m_isDrawing = false;
        m_bStart = true;
        m_bEnd = true;
        update();
    }
}

void CoveragePaintWidget::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton){
        m_endPoint = event->pos();
        m_TempBuffer = m_buffer;
        m_bStart = true;
        m_bEnd = true;
        update();
    }
}

QPoint CoveragePaintWidget::endPoint() const
{
    return m_endPoint;
}

QPoint CoveragePaintWidget::startPonit() const
{
    return m_startPonit;
}
