#include "widget.h"
#include "ui_widget.h"
#include <QGraphicsOpacityEffect>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QGraphicsOpacityEffect *effect = new QGraphicsOpacityEffect(this);
    effect->setOpacity(0.5);
    ui->pushButton->setGraphicsEffect(effect);
    ui->pushButton_2->setGraphicsEffect(effect);
    ui->pushButton_3->setGraphicsEffect(effect);
    ui->pushButton_4->setGraphicsEffect(effect);
}

Widget::~Widget()
{
    delete ui;
}
