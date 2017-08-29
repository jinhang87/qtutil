#include "widget.h"
#include "ui_widget.h"
#include "titlebar.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    m_titleBar = new TitleBar(this);

}

Widget::~Widget()
{
    delete ui;
}
