#ifndef SLIDERBUTTON_H
#define SLIDERBUTTON_H

#include <QWidget>
#include <QPushButton>

class SliderButton : public QPushButton
{
    Q_OBJECT
public:
    explicit SliderButton(Qt::MouseButton enumButton = Qt::LeftButton, QWidget *parent = 0);
protected:
    virtual void mousePressEvent(QMouseEvent * event);
    virtual void mouseMoveEvent(QMouseEvent * event);
    virtual void paintEvent(QPaintEvent *e);
    virtual QSize sizeHint() const;

signals:
    void posChanged(int value);

public slots:

private:
    int pressedPos;
    Qt::MouseButton m_enumButton = Qt::LeftButton;
};

#endif // SLIDERBUTTON_H
