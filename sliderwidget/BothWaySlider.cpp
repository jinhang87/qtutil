#include "BothWaySlider.h"

BothWaySlider::BothWaySlider(QWidget *parent)
    : QWidget(parent)
{
    _sliderWidget = new SliderWidget(this);
}

BothWaySlider::~BothWaySlider()
{

}

void BothWaySlider::resizeEvent(QResizeEvent *e)
{
    QWidget::resizeEvent(e);
    _sliderWidget->setGeometry(0, height() / 2 - 7, width(), 46);
}

int BothWaySlider::getLeftPos()
{
    return _sliderWidget->getLeftPos();
}

int BothWaySlider::getRightPos()
{
    return _sliderWidget->getRightPos();
}

void BothWaySlider::setLeftPos(int dPos)
{
    _sliderWidget->setLeftPos(dPos);
}

void BothWaySlider::setRightPos(int dPos)
{
    _sliderWidget->setRightPos(dPos);
}

void BothWaySlider::changeValue(double dLeft, double dRight)
{
    emit valueChange(dLeft, dRight);
}
