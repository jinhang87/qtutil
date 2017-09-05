#include "dialoga.h"
#include "ui_dialoga.h"
#include "dialogb.h"

DialogA::DialogA(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogA)
{
    ui->setupUi(this);
}

DialogA::~DialogA()
{
    delete ui;
}

void DialogA::on_pushButton_clicked()
{
    DialogB b;
    b.show();
    b.exec();
}
