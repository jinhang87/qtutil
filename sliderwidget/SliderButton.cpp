#include "SliderButton.h"
#include "SliderWidget.h"

SliderButton::SliderButton(QWidget *parent, SlIDERTYPE sliderType/* = TYPE_LEFT*/)
: QPushButton(parent), _sliderType(sliderType)
{

}

SliderButton::~SliderButton()
{

}

void SliderButton::mousePressEvent(QMouseEvent * event)
{
	_iPressPos = event->pos().x();
}

void SliderButton::mouseMoveEvent(QMouseEvent * event)
{
	int iChange = event->pos().x() - _iPressPos;
	dynamic_cast<SliderWidget*>(parentWidget())->sliderMove(iChange, _sliderType);
}

void SliderButton::setSliderType(SlIDERTYPE sliderType)
{
	_sliderType = sliderType;
}

SliderButton::SlIDERTYPE SliderButton::getSliderType()
{
	return _sliderType;
}
