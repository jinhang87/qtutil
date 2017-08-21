#include "weekplaner.h"
#include "weekplancopyablepanel.h"
#include "weekplaneditablepanel.h"

#include <QStateMachine>
#include <QFinalState>
#include <QDebug>

WeekPlaner::WeekPlaner(QWidget *parent) : QWidget(parent)
{
    m_stackedWidget = new QStackedWidget(this);
    m_editWidget.reset(new WeekPlanEditablePanel(this));
    m_copyWidget.reset(new WeekPlanCopyablePanel(this));
    m_stackedWidget->addWidget(m_editWidget.data());
    m_stackedWidget->addWidget(m_copyWidget.data());
    m_stackedWidget->setCurrentIndex(0);
    m_stackedWidget->show();
    machineReset();
}

QPushButton *WeekPlaner::copytopushbutton() const
{
    return m_copytopushbutton;
}

void WeekPlaner::setCopytopushbutton(QPushButton *copytopushbutton)
{
    m_copytopushbutton = copytopushbutton;
}

QSize WeekPlaner::sizeHint() const
{
    return QSize(670,400);
}

void WeekPlaner::on_deletepushbutton_clicked()
{
    m_editWidget->removeSelectedDayTrack();
}

void WeekPlaner::machineReset()
{
    m_machine.reset(new QStateMachine(this));
    QState* editState = new QState;
    QState* editSelected = new QState(editState);
    QState* editUnSelected = new QState(editState);
    QState* copyState = new QState;
    QState* copyInitial = new QState(copyState);
    QFinalState* copyOk = new QFinalState(copyState);
    QFinalState* copyCanecl = new QFinalState(copyState);
    editState->setInitialState(editUnSelected);
    copyState->setInitialState(copyInitial);
    if(m_copytopushbutton)
        editState->addTransition(m_copytopushbutton, SIGNAL(clicked()), copyState);
    editSelected->addTransition(m_editWidget.data(), SIGNAL(unSelectedSignal()), editUnSelected);
    editUnSelected->addTransition(m_editWidget.data(), SIGNAL(selectedSignal()), editSelected);
    if(m_buttonBox){
        copyInitial->addTransition(m_buttonBox, SIGNAL(accepted()), copyOk);
        copyInitial->addTransition(m_buttonBox, SIGNAL(rejected()), copyCanecl);
    }
    copyState->addTransition(copyState, SIGNAL(finished()), editState);

    connect(editState, &QState::entered, this, [=](){
        m_stackedWidget->setCurrentIndex(0);
        if(m_copytopushbutton)
            m_copytopushbutton->setDisabled(false);
        if(m_newpushbutton)
            m_newpushbutton->setDisabled(false);
        if(m_deletepushbutton)
            m_deletepushbutton->setDisabled(false);
        if(m_buttonBox)
            m_buttonBox->hide();
    });
    connect(editState, &QState::exited, this, [=](){
        qDebug() << "editState exited";
        if(m_editWidget){
            int selectedId = m_editWidget->getSelectedId();
            DayTrack* daytrack = m_editWidget->getSelectedDayTrack();
            m_stackedWidget->removeWidget(m_copyWidget.data());
            m_copyWidget.reset(new WeekPlanCopyablePanel(this));
            m_stackedWidget->addWidget(m_copyWidget.data());
            qDebug()<< m_stackedWidget->count();
            m_copyWidget->setSourceId(selectedId, daytrack);
        }
    });

    connect(editSelected, &QState::entered, this, [=](){
        qDebug() << "editSelected entered";
        if(m_copytopushbutton)
            m_copytopushbutton->setDisabled(false);
        if(m_newpushbutton)
            m_newpushbutton->setDisabled(false);
        if(m_deletepushbutton)
            m_deletepushbutton->setDisabled(false);
    });

    connect(editUnSelected, &QState::entered, this, [=](){
        qDebug() << "editUnSelected entered";
        if(m_copytopushbutton)
            m_copytopushbutton->setDisabled(true);
        if(m_newpushbutton)
            m_newpushbutton->setDisabled(true);
        if(m_deletepushbutton)
            m_deletepushbutton->setDisabled(true);
    });

    connect(copyState, &QState::entered, this, [=](){
        qDebug() << "copyState entered";
        m_stackedWidget->setCurrentIndex(1);
        if(m_copytopushbutton)
            m_copytopushbutton->setDisabled(true);
        if(m_newpushbutton)
            m_newpushbutton->setDisabled(true);
        if(m_deletepushbutton)
            m_deletepushbutton->setDisabled(true);
        if(m_buttonBox)
            m_buttonBox->show();
    });

    connect(copyOk, &QState::entered, this, [=](){
        qDebug() << "copyOk entered";
        if(m_editWidget){
            QList<int> listCheckedId = m_copyWidget->checkedId();
            m_editWidget->setCopyableId(listCheckedId);
            qDebug()<< listCheckedId;
        }
    });
    connect(copyCanecl, &QState::entered, this, [=](){
        qDebug() << "copyCanecl entered";
    });

    m_machine->addState(editState);
    m_machine->addState(copyState);
    m_machine->setInitialState(editState);
    m_machine->start();
}

QDialogButtonBox *WeekPlaner::buttonBox() const
{
    return m_buttonBox;
}

void WeekPlaner::setButtonBox(QDialogButtonBox *buttonBox)
{
    m_buttonBox = buttonBox;
    machineReset();
}

QPushButton *WeekPlaner::deletepushbutton() const
{
    return m_deletepushbutton;
}

void WeekPlaner::setDeletepushbutton(QPushButton *deletepushbutton)
{
    m_deletepushbutton = deletepushbutton;
    connect(m_deletepushbutton, &QPushButton::clicked, this, &WeekPlaner::on_deletepushbutton_clicked );
    machineReset();
}

QPushButton *WeekPlaner::newpushbutton() const
{
    return m_newpushbutton;
}

void WeekPlaner::setNewpushbutton(QPushButton *newpushbutton)
{
    m_newpushbutton = newpushbutton;
    machineReset();
}

