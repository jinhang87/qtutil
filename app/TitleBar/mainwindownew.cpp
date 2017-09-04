#include "mainwindownew.h"
#include "ui_mainwindownew.h"

MainWindowNew::MainWindowNew(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowNew)
{
    ui->setupUi(this);
}

MainWindowNew::~MainWindowNew()
{
    delete ui;
}
