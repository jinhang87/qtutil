#ifndef BOTHWAYSLIDER_H
#define BOTHWAYSLIDER_H

#include <QWidget>
#include "SliderWidget.h"

class BothWaySlider : public QWidget
{
	Q_OBJECT

public:
	BothWaySlider(QWidget *parent);
	~BothWaySlider();
	int getLeftPos();
	int getRightPos();
	void setLeftPos(int dPos);
	void setRightPos(int dPos);
	void changeValue(double dLeft, double dRight);
protected:
	virtual void resizeEvent(QResizeEvent *);
signals:
	void valueChange(double dLeft, double dRight);

private:
	SliderWidget* _sliderWidget;
};

#endif // BOTHWAYSLIDER_H
