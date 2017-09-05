#include "dialogc.h"
#include "ui_dialogc.h"

DialogC::DialogC(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogC)
{
    ui->setupUi(this);
}

DialogC::~DialogC()
{
    delete ui;
}

void DialogC::on_pushButton_clicked()
{

}
