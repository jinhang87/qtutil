#include "timetip.h"
#include "sliderbutton.h"
#include "daytrack.h"
#include <QDebug>

TimeTip::TimeTip(QWidget *parent) : QWidget(parent)
{
    left = new SliderButton(parent);
    connect(left, &SliderButton::posChanged, this, &TimeTip::onLeftPosChanged);
    right = new SliderButton(parent);
    connect(right, &SliderButton::posChanged, this, &TimeTip::onRightPosChanged);
    detail = new QPushButton(parent);
    detail->resize(200,20);
}

void TimeTip::setCentralRect(const QRect &rect)
{
    QPoint p;

    if(rect.bottomLeft().x() > left->width()){
        p = QPoint(rect.bottomLeft().x() - left->width() , rect.bottomLeft().y());
    }else{
        p = QPoint(0 , rect.bottomLeft().y());
    }
    if(p != left->pos()){
        left->move(p);
    }

    if(rect.bottomRight().x() + right->width() < parentWidget()->width() ){
        p = QPoint(rect.bottomRight().x() , rect.bottomRight().y());
    }else{
        p = QPoint(parentWidget()->width() - right->width(), rect.bottomRight().y());
    }
    if(p != right->pos()){
        right->move(p);
    }

    int x = 0, y = 0;
    x = rect.topLeft().x() + (rect.width()/2) - (detail->width()/2);
    x = (x > 0) ? x : 0;
    x = ((x + detail->width()) < parentWidget()->width()) ? x : (parentWidget()->width() - detail->width());
    y = rect.topLeft().y() - detail->height();
    p = QPoint(x, y);
    if(p != detail->pos()){
        detail->move(p);
    }
}

void TimeTip::setText(const QString &text)
{
    detail->setText(text);
}

void TimeTip::show()
{
    left->show();
    right->show();
    detail->show();
}

void TimeTip::hide()
{
    left->hide();
    right->hide();
    detail->hide();
}

DayTrack *TimeTip::getDaytrack() const
{
    return daytrack;
}

void TimeTip::setDaytrack(DayTrack *value)
{
    if(value != daytrack){
        daytrack = value;
    }
}

void TimeTip::onLeftPosChanged(int value)
{
    if(!daytrack){
        return;
    }
    bool ok = false;
    SegmentSpliter spliterSelected = daytrack->getSelectedSpliter(ok);
    SegmentSpliter spliterNew;
    spliterNew.start = spliterSelected.start + (qreal)value/daytrack->width();
    spliterNew.end  = spliterSelected.end;

    if(daytrack->setSelectedSpliter(spliterNew)){
        QString text;
        text = QString("%1~%2").arg(spliterNew.start).arg(spliterNew.end);
        detail->setText(text);
    }
}

void TimeTip::onRightPosChanged(int value)
{
    if(!daytrack){
        return;
    }

    bool ok = false;
    SegmentSpliter spliterSelected = daytrack->getSelectedSpliter(ok);
    SegmentSpliter spliterNew;
    spliterNew.start = spliterSelected.start ;
    spliterNew.end  = spliterSelected.end + (qreal)value/daytrack->width();

    if(daytrack->setSelectedSpliter(spliterNew)){
        QString text;
        text = QString("%1~%2").arg(spliterNew.start).arg(spliterNew.end);
        detail->setText(text);
    }
}
