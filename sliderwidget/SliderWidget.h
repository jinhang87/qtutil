#ifndef SLIDERWIDGET_H
#define SLIDERWIDGET_H

#include "SliderButton.h"
#include <QFrame>

class SliderWidget : public QFrame
{
	Q_OBJECT

public:
	SliderWidget(QWidget *parent);
	~SliderWidget();
	int getLeftPos();
	int getRightPos();
	void setLeftPos(int dPos);
	void setRightPos(int dPos);
	void sliderMove(int iLength, SliderButton::SlIDERTYPE sliderType);
protected:
	virtual void resizeEvent(QResizeEvent *);
private:
	void setLeftSliderGeomtry();
	void setRightSliderGeomtry();

private:
	SliderButton* _leftSlider;
	SliderButton* _rightSlider;
	double _dLeftPos;
	double _dRightPos;
};

#endif // SLIDERWIDGET_H
