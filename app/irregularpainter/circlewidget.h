#ifndef CIRCLEWIDGET_H
#define CIRCLEWIDGET_H

#include <QWidget>

class CircleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CircleWidget(QWidget *parent = 0);
protected:
    virtual void paintEvent(QPaintEvent *event) override;
    virtual QSize sizeHint() const override;

signals:

public slots:
};

#endif // CIRCLEWIDGET_H
