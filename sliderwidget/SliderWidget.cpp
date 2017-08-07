#include "SliderWidget.h"
#include "BothWaySlider.h"

SliderWidget::SliderWidget(QWidget *parent)
	: QFrame(parent), _dLeftPos(0.0), _dRightPos(1.0)
{
	setObjectName("Slider");
	setStyleSheet("#Slider{border:1px solid gray}");
	_leftSlider = new SliderButton(this);
	_rightSlider = new SliderButton(this, SliderButton::TYPE_RIGHT);
}

SliderWidget::~SliderWidget()
{

}

void SliderWidget::resizeEvent(QResizeEvent *e)
{
	QFrame::resizeEvent(e);
	setLeftSliderGeomtry();
	setRightSliderGeomtry();
}

void SliderWidget::setLeftSliderGeomtry()
{
	_dLeftPos = _dLeftPos > _dRightPos ? _dRightPos : _dLeftPos;
	_dLeftPos = _dLeftPos >= 0.0 ? _dLeftPos : 0.0;
	_leftSlider->setGeometry((width() - 15) * _dLeftPos, 0, 15, height());
	QString qStrTips = QString::number(_dLeftPos * 100, 'f', 2);
	qStrTips += "%";
	_leftSlider->setToolTip(qStrTips);
	dynamic_cast<BothWaySlider*>(parentWidget())->changeValue(_dLeftPos, _dRightPos);
}

void SliderWidget::setRightSliderGeomtry()
{
	_dRightPos = _dLeftPos > _dRightPos ? _dLeftPos : _dRightPos;
	_dRightPos = _dRightPos <= 1.0 ? _dRightPos : 1.0; 
	_rightSlider->setGeometry((width() - 15) * _dRightPos, 0, 15, height());
	QString qStrTips = QString::number(_dRightPos * 100, 'f', 2);
	qStrTips += "%";
	_rightSlider->setToolTip(qStrTips);
	dynamic_cast<BothWaySlider*>(parentWidget())->changeValue(_dLeftPos, _dRightPos);
}

int SliderWidget::getLeftPos()
{
	return _dLeftPos;
}

int SliderWidget::getRightPos()
{
	return _dRightPos;
}

void SliderWidget::setLeftPos(int dPos)
{
	_dLeftPos = dPos;
	setLeftSliderGeomtry();
}

void SliderWidget::setRightPos(int dPos)
{
	_dRightPos = dPos;
	setRightSliderGeomtry();
}

void SliderWidget::sliderMove(int iLength, SliderButton::SlIDERTYPE sliderType)
{
	switch (sliderType)
	{
	case SliderButton::TYPE_LEFT:
		{
			_dLeftPos += iLength * 1.0 / (width() - 15);
			setLeftSliderGeomtry();
		}		
		break;
	case SliderButton::TYPE_RIGHT:
		{
			_dRightPos += iLength * 1.0 / (width() - 15);
			setRightSliderGeomtry();
		}
		break;
	}
}
