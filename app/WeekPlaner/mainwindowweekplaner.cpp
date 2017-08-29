#include "mainwindowweekplaner.h"
#include "ui_mainwindowweekplaner.h"

MainWindowWeekPlaner::MainWindowWeekPlaner(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowWeekPlaner)
{
    ui->setupUi(this);
    ui->weekplaner->setCopytopushbutton(ui->copyto);
    ui->weekplaner->setNewpushbutton(ui->new_2);
    ui->weekplaner->setDeletepushbutton(ui->delete_2);
    ui->weekplaner->setButtonBox(ui->buttonBox);
    //ui->
    //ui->widget->setCopytopushbutton(ui->copyto);
}

MainWindowWeekPlaner::~MainWindowWeekPlaner()
{
    delete ui;
}
