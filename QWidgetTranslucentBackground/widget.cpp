#include "widget.h"
#include "ui_widget.h"
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include <QDebug>

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
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(onPushButtonClicked()));


}

Widget::~Widget()
{
    delete ui;
}

void Widget::onPushButtonClicked()
{
    qDebug()<< "onPushButtonClicked";
    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity");
    animation->setDuration(1000);
    animation->setStartValue(0);
    animation->setEndValue(1);
    animation->start();
}
