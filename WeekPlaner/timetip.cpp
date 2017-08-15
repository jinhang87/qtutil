#include "timetip.h"
#include "sliderbutton.h"

TimeTip::TimeTip(QWidget *parent) : QWidget(parent)
{
    left = new SliderButton(parent);
    left->move(100,100);
    right = new SliderButton(parent);
    right->move(200,100);
    detail = new QPushButton(parent);
    detail->resize(100,50);
    detail->move(300,100);

    setCentralRect(QRect(300,100,50,10));
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
