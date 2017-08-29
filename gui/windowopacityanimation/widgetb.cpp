#include "widgetb.h"
#include "ui_widgetb.h"

WidgetB::WidgetB(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetB)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground, true);
}

WidgetB::~WidgetB()
{
    delete ui;
}
