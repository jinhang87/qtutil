#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStateMachine>
#include <QFinalState>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QState *s1 = new QState();
    s1->assignProperty(ui->pushButton, "text", "Click me");
    QState *s2 = new QState();
    QState *s3 = new QState();
    s3->addTransition(ui->pushButton, SIGNAL(clicked()), s1);
    s2->addTransition(ui->pushButton, SIGNAL(clicked()), s3);
    s1->addTransition(ui->pushButton, SIGNAL(clicked()), s2);
    machine.addState(s1);
    machine.addState(s2);
    machine.addState(s3);
    machine.setInitialState(s1);
    machine.start();
}

MainWindow::~MainWindow()
{
    delete ui;
}
