#include "daytrack.h"
#include <QDebug>
#include <QPainter>
#include <QMouseEvent>

DayTrack::DayTrack(QWidget *parent) : QFrame(parent), selected(-1)
{
    //setObjectName("DayTrack");
    //setStyleSheet("#DayTrack{border:1px solid gray;margin:13px}");
    //setFrameStyle(QFrame::Panel | QFrame::Box);

    SegmentSpliter spliter;
    spliter.start = (qreal)1/24;
    spliter.end = (qreal)3/24;
    spliters << spliter;
    qDebug() << spliter.start << spliter.end ;

    spliter.start = (qreal)5/24;
    spliter.end = (qreal)8/24;
    spliters << spliter;
    spliter.start = (qreal)11/24;
    spliter.end = (qreal)24/24;
    spliters << spliter;
}

DayTrack::~DayTrack()
{
    spliters.clear();
}

QSize DayTrack::sizeHint() const
{
    return QSize(600, 30);
}

void DayTrack::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(QPen(QColor(0, 160, 230), 2));

    qDebug() << painter.viewport();

    QColor norm = QColor(255, 160, 90);
    QColor hover = QColor(255, 77, 90);
    QRect selectedRect = QRect(0,0,0,0);
    if (selected >= 0 && selected < spliters.size())
        selectedRect = spliterToRect(spliters.at(selected));

    QListIterator<SegmentSpliter> it(spliters);
    while (it.hasNext()) {
        QRect rect = spliterToRect(it.next());
        QColor color = (selectedRect==rect) ? hover : norm;
        painter.setBrush(color);
        painter.drawRect(rect);

    }
}

void DayTrack::mousePressEvent(QMouseEvent *e)
{
    qDebug() << e->globalPos() << e->pos();
    QListIterator<SegmentSpliter> it(spliters);
    int cout = 0;
    while (it.hasNext()) {
        QRect rect = spliterToRect(it.next());
        qDebug() << e->pos() << rect;
        if(rect.contains(e->pos())){
            qDebug() << cout << "contains";
            selected = cout;
            update();
            emit spliterClicked(cout, rect);
            break;
        }else{
        }
        cout++;
    }

    if(cout == spliters.size()){
        qDebug() << cout << "not contains";
        selected = -1;
        update();
        emit spliterOutsideClicked();
    }
}

QRect DayTrack::spliterToRect(const SegmentSpliter &spliter)
{
    int x = spliter.start * width();
    int w = (spliter.end - spliter.start) * width();
    int y = 0;
    int h = height();
    return QRect(x, y, w, h);
}

int DayTrack::getSelected() const
{
    return selected;
}

void DayTrack::setSelected(int value)
{
    if(value >= 0 && value < spliters.size()){
        selected = value;
    }
    else{
        selected = -1;
    }
    update();
}

QList<SegmentSpliter> DayTrack::getSpliters() const
{
    return spliters;
}

void DayTrack::setSpliters(const QList<SegmentSpliter> &value)
{
    spliters = value;
    update();
}

