#include "timetip.h"
#include "sliderbutton.h"
#include "daytrack.h"
#include <QDebug>

TimeTip::TimeTip(QWidget *parent) : QObject(parent)
{
    left = new SliderButton(parent);
    right = new SliderButton(parent);
    detail = new QPushButton(parent);
    detail->resize(100,20);
    //setCentralRect(QRect(300,100,50,10));
}

void TimeTip::setCentralRect(const QRect &rect)
{
    QPoint p;

    p = QPoint(rect.bottomLeft().x() - left->width() , rect.bottomLeft().y());
    left->move(p);

    p = QPoint(rect.bottomRight().x() , rect.bottomRight().y());
    right->move(p);

    p = QPoint(rect.topLeft().x() + (rect.width()/2) - (detail->width()/2), rect.topLeft().y() - detail->height() - 15);
    detail->move(p);

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
    if(value){
        daytrack = value;
        QList<SegmentSpliter> list = daytrack->getSpliters();
        SegmentSpliter spliter = list[daytrack->getSelected()];
        connect(left, &SliderButton::posChanged, this, [=](int value){
            qDebug() << value << spliter.start << spliter.end << daytrack->size();
            spliter.start -= (qreal)value/daytrack->width();
            qDebug() << spliter.start;
        });
    }
}
