#ifndef DAYTRACK_H
#define DAYTRACK_H

#include <QFrame>
#include <QList>

struct SegmentSpliter
{
    qreal start;
    qreal end;
};

class DayTrack : public QFrame
{
    Q_OBJECT
public:
    explicit DayTrack(QWidget *parent = 0);
    virtual ~DayTrack();

    QList<SegmentSpliter> getSpliters() const;
    void setSpliters(const QList<SegmentSpliter> &value);

    int getSelected() const;
    void setSelected(int value);

protected:
    virtual QSize sizeHint() const;
    virtual void paintEvent(QPaintEvent *e);
    virtual void mousePressEvent(QMouseEvent *e);

signals:
    void spliterClicked(int index, QRect rect);
    void spliterOutsideClicked();

public slots:

private:
    QRect spliterToRect(const SegmentSpliter &spliter);
    QList<SegmentSpliter> spliters;
    int selected;
};

#endif // DAYTRACK_H
