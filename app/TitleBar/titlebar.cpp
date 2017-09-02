#include "titlebar.h"
#include "ui_titlebar.h"

TitleBar::TitleBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TitleBar)
{
    ui->setupUi(this);
}

TitleBar::~TitleBar()
{
    delete ui;
}

void TitleBar::on_pushButton_clicked()
{
    if(parentWidget()){
        if(parentWidget()->parentWidget()){
            parentWidget()->parentWidget()->close();
        }
    }
}
