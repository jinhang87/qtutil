#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setStyleSheet(tr("background-color: blue"));
}

Widget::~Widget()
{
    delete ui;
}
