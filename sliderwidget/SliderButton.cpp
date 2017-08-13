#include "SliderButton.h"
#include "SliderWidget.h"
#include <QPainter>
#include <QPainterPath>

SliderButton::SliderButton(QWidget *parent, SlIDERTYPE sliderType/* = TYPE_LEFT*/)
: QPushButton(parent), _sliderType(sliderType)
{
    setObjectName("SliderButton");
    //setStyleSheet("#SliderButton{border:3px}");
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

void SliderButton::paintEvent(QPaintEvent *e)
{
    QPainter painter(this); //创建painter
    painter.setRenderHint(QPainter::Antialiasing, true); //消除锯齿效果

    QPainterPath path;
    path.moveTo(0, 6);
    path.lineTo(0, 12);
    path.lineTo(12, 12);
    path.lineTo(12, 0);
    path.lineTo(0, 6);

    //path->setFillRule(Qt::WindingFill);
    //设置无画笔，避免边框出现一条黑线
    painter.setPen(Qt::NoPen);
    //设置画刷
    painter.setBrush(QBrush(QColor(36,169,225), Qt::SolidPattern));
    //绘制背景
    painter.drawPath(path);

    e->accept();//不再向父类传递消息
}

void SliderButton::setSliderType(SlIDERTYPE sliderType)
{
	_sliderType = sliderType;
}

SliderButton::SlIDERTYPE SliderButton::getSliderType()
{
	return _sliderType;
}
