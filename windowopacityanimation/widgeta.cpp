#include "widgeta.h"
#include "ui_widgeta.h"

WidgetA::WidgetA(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetA)
{
    ui->setupUi(this);
    setWindowOpacity(0.2);
}

WidgetA::~WidgetA()
{
    delete ui;
}
