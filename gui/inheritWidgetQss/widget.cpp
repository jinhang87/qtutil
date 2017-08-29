#include "widget.h"
#include "ui_widget.h"
#include <QGraphicsBlurEffect>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pushButton->setStyleSheet("background-color: green");
    ui->label->setStyleSheet("QLabel:hover { padding: 3px }");
    dialog = new Dialog(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_2_clicked()
{
    dialog->show();
    ui->pushButton->setStyleSheet("background-color: red");
    QGraphicsBlurEffect *effect = new QGraphicsBlurEffect;
    effect->setBlurRadius(4);
    setGraphicsEffect(effect);
}
