#include "daytrack.h"
#include <QDebug>
#include <QPainter>
#include <QMouseEvent>

DayTrack::DayTrack(QWidget *parent) : QFrame(parent), selected(-1)
{
    //setObjectName("DayTrack");
    //setStyleSheet("#DayTrack{border:1px solid gray;margin:13px}");
    //setFrameStyle(QFrame::Panel | QFrame::Box);
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
    QListIterator<SegmentSpliter> it(spliters);
    int cout = 0;
    while (it.hasNext()) {
        QRect rect = spliterToRect(it.next());
        if(rect.contains(e->pos())){
            selected = cout;
            update();
            emit spliterClicked(cout, rect);
            break;
        }else{
        }
        cout++;
    }

    if(cout == spliters.size()){
        selected = -1;
        update();
        emit spliterOutsideClicked();
    }
}

void DayTrack::resizeEvent(QResizeEvent *e)
{
    Q_UNUSED(e);
    QListIterator<SegmentSpliter> it(spliters);
    int cout = 0;
    while (it.hasNext()) {
        SegmentSpliter spliter = it.next();
        if(cout==selected){
            QRect rect = spliterToRect(spliter);
            emit spliterClicked(cout, rect);
            break;
        }
        cout++;
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

SegmentSpliter DayTrack::rectToSpliter(const QRect &rect)
{
    SegmentSpliter spliter;
    spliter.start = (qreal)rect.x()/width();
    spliter.end = (qreal)rect.width()/width()+spliter.start;
    return spliter;
}

int DayTrack::getSelected() const
{
    return selected;
}

void DayTrack::setSelected(int value)
{
    int last = selected;
    if(value >= 0 && value < spliters.size()){
        selected = value;
    }
    else{
        selected = -1;
    }

    if(last != selected){
        update();
    }
}

QRect DayTrack::getSelectedRect()
{
    QRect rect = QRect(0,0,0,0);
    if(selected >= 0 && selected < spliters.size()){
        rect = spliterToRect(spliters.at(selected));
    }
    return rect;
}

void DayTrack::removeSelected()
{
    if(selected >= 0 && selected < spliters.size()){
        spliters.removeAt(selected);
        update();
        emit spliterOutsideClicked();
    }
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

void DayTrack::clearSpliters()
{
    QList<SegmentSpliter> list;
    list.clear();
    setSpliters(list);
}

void DayTrack::fullSpliters()
{
    SegmentSpliter spliter;
    spliter.start = 0;
    spliter.end = 1;
    QList<SegmentSpliter> list;
    list << spliter;
    setSpliters(list);
}

SegmentSpliter DayTrack::getSelectedSpliter(bool &ok) const
{
    if(selected >= 0 && selected < spliters.size()){
        ok = true;
        return spliters[selected];
    }else{
        SegmentSpliter null;
        null.start = null.end = 0;
        ok = false;
        return null;
    }
}

bool DayTrack::intersectsExceptSelected(const SegmentSpliter &value) const
{
    QListIterator<SegmentSpliter> it(spliters);
    int cout = 0;
    while (it.hasNext()) {
        SegmentSpliter spliter = it.next();
        if(cout == selected){
            cout++;
            continue;
        }
        if(value.intersects(spliter)){
            return true;
        }
        cout++;
    }
    return false;
}

bool DayTrack::setSelectedSpliter(const SegmentSpliter &value)
{
    if(selected >= 0 && selected < spliters.size()){
        if(intersectsExceptSelected(value)){
            return false;
        }
        if(value.start >= value.end){
            return false;
        }
        if(value.start<0 || value.end>1){
            return false;
        }
        if(value != spliters[selected]){
            spliters[selected] = value;
            update();
            QRect rect = spliterToRect(value);
            emit spliterClicked(selected, rect);
            return true;
        }
    }
    return false;
}

