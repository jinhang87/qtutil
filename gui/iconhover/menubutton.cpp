#include "menubutton.h"
#include <QLabel>
#include <QIcon>
#include <QPushButton>

MenuButton::MenuButton(QWidget *parent) : QWidget(parent)
{
    QLabel *label = new QLabel(this);
    label->setText("upgrade");
    QIcon *icon = new QIcon();

    QPixmap *pixmap1 = new QPixmap(":/image/主菜单-click.png");
    QPixmap *pixmap2 = new QPixmap(":/image/主菜单-normal.png");
    icon->addPixmap(*pixmap1, QIcon::Normal);
    icon->addPixmap(*pixmap2, QIcon::Selected);
    QPushButton *button = new QPushButton(this);
    button->setIcon(*icon);
    button->resize(200,200);
    button->setIconSize(QSize(200,200));

}

void MenuButton::paintEvent(QPaintEvent *)
{

}
