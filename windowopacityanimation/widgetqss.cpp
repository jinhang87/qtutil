#include "widgetqss.h"
#include "ui_widgetqss.h"

WidgetQss::WidgetQss(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetQss)
{
    ui->setupUi(this);
    setStyleSheet("QLabel{background-color: rgba(255, 11, 224, 10%);}");
}

WidgetQss::~WidgetQss()
{
    delete ui;
}
