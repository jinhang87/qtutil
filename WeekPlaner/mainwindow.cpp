#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "daytrackgroup.h"
#include "timetip.h"
#include "weekplaneditablepanel.h"
#include "weekplancopyablepanel.h"
#include <QDebug>
#include <QMouseEvent>
#include <QStateMachine>
#include <QFinalState>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    copyWidget = QSharedPointer<WeekPlanCopyablePanel>(new WeekPlanCopyablePanel(this));
    ui->stackedWidget->setCurrentIndex(0);
    resetCopyWidget();

    QStateMachine *machine = new QStateMachine(this);
    QState* editState = new QState;
    QState* editInitial = new QState(editState);
    QState* editSelected = new QState(editState);
    QState* editUnSelected = new QState(editState);
    QState* copyState = new QState;
    QState* copyInitial = new QState(copyState);
    QFinalState* copyOk = new QFinalState(copyState);
    QFinalState* copyCanecl = new QFinalState(copyState);
    editState->setInitialState(editInitial);
    copyState->setInitialState(copyInitial);
    editState->addTransition(ui->copytopushbutton, SIGNAL(clicked()), copyState);
    WeekPlanEditablePanel* editWidget1 = qobject_cast<WeekPlanEditablePanel*>(ui->stackedWidget->widget(0));
    editInitial->addTransition(editWidget1, SIGNAL(selectedSignal()), editSelected);
    editInitial->addTransition(editWidget1, SIGNAL(unSelectedSignal()), editUnSelected);
    editSelected->addTransition(editWidget1, SIGNAL(unSelectedSignal()), editUnSelected);
    editUnSelected->addTransition(editWidget1, SIGNAL(selectedSignal()), editSelected);
    copyInitial->addTransition(ui->buttonBox, SIGNAL(accepted()), copyOk);
    copyInitial->addTransition(ui->buttonBox, SIGNAL(rejected()), copyCanecl);
    copyState->addTransition(copyState, SIGNAL(finished()), editState);

    connect(editState, &QState::entered, this, [=](){
        ui->stackedWidget->setCurrentIndex(0);
        ui->copytopushbutton->setDisabled(false);
        ui->newpushbutton->setDisabled(false);
        ui->deletepushbutton->setDisabled(false);
        ui->buttonBox->hide();
    });
    connect(editState, &QState::exited, this, [=](){
        qDebug() << "editState exited";
        WeekPlanEditablePanel* editWidget = qobject_cast<WeekPlanEditablePanel*>(ui->stackedWidget->widget(0));
        if(editWidget){
            int selectedId = editWidget->getSelectedId();
            DayTrack* daytrack = editWidget->getSelectedDayTrack();
            resetCopyWidget();
            qDebug()<< ui->stackedWidget->count();
            copyWidget->setSourceId(selectedId, daytrack);
        }
    });
    connect(editSelected, &QState::entered, this, [=](){
        qDebug() << "editSelected entered";
        ui->newpushbutton->setDisabled(false);
        ui->deletepushbutton->setDisabled(false);
    });
    connect(editUnSelected, &QState::entered, this, [=](){
        qDebug() << "editUnSelected entered";
        ui->newpushbutton->setDisabled(true);
        ui->deletepushbutton->setDisabled(true);
    });
    connect(copyState, &QState::entered, this, [=](){
        qDebug() << "copyState entered";
        ui->stackedWidget->setCurrentIndex(1);
        ui->copytopushbutton->setDisabled(true);
        ui->newpushbutton->setDisabled(true);
        ui->deletepushbutton->setDisabled(true);
        ui->buttonBox->show();
    });
    connect(editInitial, &QState::entered, this, [=](){
        qDebug() << "editInitial entered";
    });
    connect(copyOk, &QState::entered, this, [=](){
        qDebug() << "copyOk entered";
        WeekPlanEditablePanel* editWidget = qobject_cast<WeekPlanEditablePanel*>(ui->stackedWidget->widget(0));
        if(editWidget){
            QList<int> listCheckedId = copyWidget->checkedId();
            editWidget->setCopyableId(listCheckedId);
            qDebug()<< listCheckedId;
        }
    });
    connect(copyCanecl, &QState::entered, this, [=](){
        qDebug() << "copyCanecl entered";
    });

    machine->addState(editState);
    machine->addState(copyState);
    machine->setInitialState(editState);
    machine->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    qDebug() << "mousePressEvent" << e->pos();
}

void MainWindow::on_copytopushbutton_clicked()
{
}

void MainWindow::on_newpushbutton_clicked()
{

}

void MainWindow::on_deletepushbutton_clicked()
{

}

void MainWindow::on_clearpushbutton_clicked()
{
}

void MainWindow::resetCopyWidget()
{
    ui->stackedWidget->removeWidget(copyWidget.data());
    copyWidget.reset(new WeekPlanCopyablePanel(this));
    ui->stackedWidget->addWidget(copyWidget.data());
}

