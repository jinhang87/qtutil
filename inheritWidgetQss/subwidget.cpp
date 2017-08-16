#include "subwidget.h"
#include <QPainter>
#include <QStyleOption>

SubWidget::SubWidget(QWidget *parent) : QWidget(parent)
{
    //setStyleSheet(tr("background-color: yellow"));
}

void SubWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
#if 1 //如果没有paintEvent重载，yellow颜色显示不出来
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
#endif
}
