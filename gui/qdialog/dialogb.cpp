#include "dialogb.h"
#include "ui_dialogb.h"
#include "dialogc.h"

DialogB::DialogB(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogB)
{
    ui->setupUi(this);
}

DialogB::~DialogB()
{
    delete ui;
}

void DialogB::on_pushButton_clicked()
{
    DialogC c;
    c.show();
    c.exec();
}
