#ifndef TIMETIP_H
#define TIMETIP_H

#include <QWidget>
#include <QRect>
#include <QPushButton>

class SliderButton;
class DayTrack;
class TimeTip : public QObject
{
    Q_OBJECT
public:
    explicit TimeTip(QWidget *parent = 0);
    void setCentralRect(const QRect& rect);
    void show();
    void hide();

    DayTrack *getDaytrack() const;
    void setDaytrack(DayTrack *value);

signals:

public slots:

private:
    SliderButton* left;
    SliderButton* right;
    QPushButton* detail;
    DayTrack *daytrack;
};

#endif // TIMETIP_H
