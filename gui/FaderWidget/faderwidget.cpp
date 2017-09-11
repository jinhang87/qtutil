#include "faderwidget.h"
#include <QTimer>
#include <QPainter>

FaderWidget::FaderWidget(QWidget *parent) : QWidget(parent)
{
    if (parent)
        startColor = parent->palette().window().color();
    else
        startColor = Qt::white;

    currentAlpha = 0;
    fadeTimes = 2000;

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this, SLOT(update()));

    setAttribute(Qt::WA_DeleteOnClose);
    resize(parent->size());
}

void FaderWidget::start()
{
    currentAlpha = 255;
    timer->start(100);
    show();
}

void FaderWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QColor currentColor = startColor;
    currentColor.setAlpha(currentAlpha);
    painter.fillRect(rect(), currentColor);

    currentAlpha -= 255 * timer->interval() / fadeTimes;
    if (currentAlpha <= 0){
        timer->stop();
        close();
    }
}
