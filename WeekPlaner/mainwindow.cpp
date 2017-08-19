#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "daytrackgroup.h"
#include "timetip.h"
#include "weekplaneditablepanel.h"
#include "weekplancopyablepanel.h"
#include <QDebug>
#include <QMouseEvent>
#include <QStateMachine>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);


    QStateMachine *machine = new QStateMachine(this);
    QState* editState = new QState;
    QState* copyState = new QState;
    editState->addTransition(ui->copytopushbutton, SIGNAL(clicked()), copyState);
    copyState->addTransition(ui->okpushButton, SIGNAL(clicked()), editState);

    //WeekPlanEditablePanel* editWidget = qobject_cast<WeekPlanEditablePanel*>(ui->stackedWidget->widget(0));
    //WeekPlanCopyablePanel* copyWidget = qobject_cast<WeekPlanCopyablePanel*>(ui->stackedWidget->widget(1));

    connect(editState, &QState::entered, this, [&](){
        qDebug()<< "editState entered";
        WeekPlanEditablePanel* editWidget = qobject_cast<WeekPlanEditablePanel*>(ui->stackedWidget->widget(0));
        editWidget->setCopyableId(copyWidgetCheckedId);
        ui->stackedWidget->setCurrentIndex(0);
    });

    connect(editState, &QState::exited, this, [&](){
        qDebug()<< "editState exited";
        WeekPlanEditablePanel* editWidget = qobject_cast<WeekPlanEditablePanel*>(ui->stackedWidget->widget(0));
        editWidgetSelectedId = editWidget->getSelectedId();
        editWidgetSelectedDaytrack = editWidget->getSelectedDayTrack();
        qDebug()<< editWidgetSelectedId;
    });

    connect(copyState, &QState::entered, this, [&](){
        qDebug()<< "copyState entered";
        WeekPlanCopyablePanel* copyWidget = qobject_cast<WeekPlanCopyablePanel*>(ui->stackedWidget->widget(1));
        copyWidget->clear();
        copyWidget->setSourceId(editWidgetSelectedId, editWidgetSelectedDaytrack);
        ui->stackedWidget->setCurrentIndex(1);
    });

    connect(copyState, &QState::exited, this, [&](){
        qDebug()<< "copyState exited";
        WeekPlanCopyablePanel* copyWidget = qobject_cast<WeekPlanCopyablePanel*>(ui->stackedWidget->widget(1));
        copyWidgetCheckedId = copyWidget->checkedId();
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
#if 0
    WeekPlanEditablePanel* editWidget = qobject_cast<WeekPlanEditablePanel*>(ui->stackedWidget->widget(0));
    WeekPlanCopyablePanel* copyWidget = qobject_cast<WeekPlanCopyablePanel*>(ui->stackedWidget->widget(1));
    if(editWidget && copyWidget){
        int selectedId = editWidget->getSelectedId();
        DayTrack* daytrack = editWidget->getSelectedDayTrack();
        copyWidget->clear();
        copyWidget->setSourceId(selectedId, daytrack);
        ui->stackedWidget->setCurrentIndex(1);
    }
#endif
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

void MainWindow::on_okpushButton_clicked()
{
#if 0
    WeekPlanEditablePanel* editWidget = qobject_cast<WeekPlanEditablePanel*>(ui->stackedWidget->widget(0));
    WeekPlanCopyablePanel* copyWidget = qobject_cast<WeekPlanCopyablePanel*>(ui->stackedWidget->widget(1));
    if(editWidget && copyWidget){
        QList<int> listCheckedId = copyWidget->checkedId();
        editWidget->setCopyableId(listCheckedId);
        ui->stackedWidget->setCurrentIndex(0);
    }
#endif
}

void MainWindow::on_cancelpushButton_clicked()
{

}
