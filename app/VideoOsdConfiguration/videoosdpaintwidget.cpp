#include "videoosdpaintwidget.h"
#include <QDateTime>
#include <QEvent>
#include <QDebug>
#include <QPainter>

VideoOsdPaintWidget::VideoOsdPaintWidget(QWidget *parent) : QWidget(parent)
{
    m_layout = new QGridLayout(this);
    m_layout->setHorizontalSpacing(0);
    m_layout->setVerticalSpacing(0);
    //QDateTime datetime = QDateTime::currentDateTime();
    m_label = new QLabel(this);
    for(int row = 0; row < m_row; row ++){
        for(int column = 0; column < m_column; column ++){
            QWidget *w = new QWidget(this);
            w->setStyleSheet("border: 1px solid black");
            w->installEventFilter(this);
            m_layout->addWidget(w, row, column);
            m_hashWidgets[w] = QPoint(row, column);
        }
    }
    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, [=](){
        QDateTime datetime = QDateTime::currentDateTime();
        m_label->setText(datetime.toString("yyyy.M.d h:m:s ap"));
        m_label->raise();
    });
    timer->start(500);
}
void VideoOsdPaintWidget::paintEvent(QPaintEvent *event)
{
#if 0
    QPainter p(this);
    p.setCompositionMode(QPainter::CompositionMode_Clear);
    p.fillRect(rect() ,Qt::SolidPattern);
    p.end();
#endif
    QWidget::paintEvent(event);
}

bool VideoOsdPaintWidget::eventFilter(QObject *watched, QEvent *event)
{
    QWidget* w = qobject_cast<QWidget*>(watched);
    if(w && m_hashWidgets.contains(w)){
        if(event->type() == QEvent::MouseButtonRelease){
            m_label->move(w->pos());
            return true;
        }
    }
    return QWidget::eventFilter(watched, event);
}
