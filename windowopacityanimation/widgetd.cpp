#include "widgetd.h"
#include "ui_widgetd.h"

WidgetD::WidgetD(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetD)
{
    ui->setupUi(this);
    QPalette pal = palette();
    pal.setColor(QPalette::Background, QColor(0x00,0xff,0x00,0x00));
    setPalette(pal);
}

WidgetD::~WidgetD()
{
    delete ui;
}
