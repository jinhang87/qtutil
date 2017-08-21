#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStateMachine>
#include <QFinalState>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    machineReset();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_3_clicked()
{
    machineReset();
}

void MainWindow::machineReset()
{
    machine.reset(new QStateMachine());
    QState *s1 = new QState();
    s1->assignProperty(ui->pushButton, "text", "Click me s1");
    QState *s2 = new QState();
    s2->assignProperty(ui->pushButton, "text", "Click me s2");
    QState *s3 = new QState();
    s3->assignProperty(ui->pushButton, "text", "Click me s3");
    s3->addTransition(ui->pushButton, SIGNAL(clicked()), s1);
    s2->addTransition(ui->pushButton, SIGNAL(clicked()), s3);
    s1->addTransition(ui->pushButton, SIGNAL(clicked()), s2);
    machine->addState(s1);
    machine->addState(s2);
    machine->addState(s3);
    machine->setInitialState(s1);
    machine->start();
}
