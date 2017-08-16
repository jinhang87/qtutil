#include "subwidget.h"
#include <QPainter>
#include <QStyleOption>

SubWidget::SubWidget(QWidget *parent) : QWidget(parent)
{
    setStyleSheet(tr("background-color: yellow"));
}

//如果没有paintEvent重载，yellow颜色显示不出来
void SubWidget::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
