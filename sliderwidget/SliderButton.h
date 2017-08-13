#ifndef SLIDERBUTTON_H
#define SLIDERBUTTON_H

#include <QPushButton>
#include <QMouseEvent>

class SliderButton : public QPushButton
{
	Q_OBJECT
	
public:
	enum SlIDERTYPE
	{
		TYPE_LEFT = 0,
		TYPE_RIGHT
	};
	SliderButton(QWidget *parent, SlIDERTYPE sliderType = TYPE_LEFT);
	SlIDERTYPE getSliderType();
	void setSliderType(SlIDERTYPE sliderType);
	~SliderButton();
protected:
	virtual void mousePressEvent(QMouseEvent * event);
	virtual void mouseMoveEvent(QMouseEvent * event);
    virtual void paintEvent(QPaintEvent *e);

private:
	int _iPressPos;
	SlIDERTYPE _sliderType;
};

#endif // SLIDERBUTTON_H
