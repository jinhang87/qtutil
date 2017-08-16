#ifndef DAYTRACK_H
#define DAYTRACK_H

#include <QFrame>
#include <QList>

struct SegmentSpliter
{
    qreal start;
    qreal end;

    bool operator==(const SegmentSpliter &other) const{
        if(start == other.start && end == other.end){
            return true;
        }else{
            return false;
        }
    }
    bool operator!=(const SegmentSpliter &other) const{
        if(start != other.start || end != other.end){
            return true;
        }else{
            return false;
        }
    }
};

class DayTrack : public QFrame
{
    Q_OBJECT
public:
    explicit DayTrack(QWidget *parent = 0);
    virtual ~DayTrack();

    QList<SegmentSpliter> getSpliters() const;
    void setSpliters(const QList<SegmentSpliter> &value);
    bool setSelectedSpliter(const SegmentSpliter& value);
    SegmentSpliter getSelectedSpliter(bool &ok) const;
    int getSelected() const;
    void setSelected(int value);
    QRect getSelectedRect();
    QRect spliterToRect(const SegmentSpliter &spliter);

protected:
    virtual QSize sizeHint() const;
    virtual void paintEvent(QPaintEvent *e);
    virtual void mousePressEvent(QMouseEvent *e);

signals:
    void spliterClicked(int index, QRect rect);
    void spliterOutsideClicked();

public slots:

private:
    QList<SegmentSpliter> spliters;
    int selected;
};

#endif // DAYTRACK_H
