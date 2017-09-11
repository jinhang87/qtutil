#include "playbackdialog.h"
#include "ui_playbackdialog.h"
#include "playbackeditbar.h"
#include <QPropertyAnimation>
#include <QSignalTransition>
#include <QEventTransition>
#include <QState>
#include <QDebug>

PlayBackDialog::PlayBackDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlayBackDialog)
{
    ui->setupUi(this);
    setStyleSheet("QFrame { background : yellow ; }");

    m_frameEdit = new PlayBackEditBar(this);
    m_frameEdit->resize(width(), 80);
    qDebug() << m_frameEdit->geometry();

    machineReset();
}

PlayBackDialog::~PlayBackDialog()
{
    delete ui;
}

void PlayBackDialog::machineReset()
{
    m_machine.reset(new QStateMachine());
    QState* s1 = new QState();
    QState* s2 = new QState();
    QState* s3 = new QState();

    s1->assignProperty(ui->frame, "pos", QPoint(0,-ui->frame->height()));
    s1->assignProperty(ui->frame_2, "pos", QPoint(0,this->height()));
    s1->assignProperty(m_frameEdit, "pos", QPoint(0,this->height()));

    s2->assignProperty(ui->frame, "pos", QPoint(0,0));
    s2->assignProperty(ui->frame_2, "pos", QPoint(0, this->height()-ui->frame_2->height()));
    s2->assignProperty(m_frameEdit, "pos", QPoint(0,this->height()));

    s3->assignProperty(ui->frame, "pos", QPoint(0,0));
    s3->assignProperty(ui->frame_2, "pos", QPoint(0, this->height()));
    s3->assignProperty(m_frameEdit, "pos", QPoint(0, this->height()-m_frameEdit->height()));

    QPropertyAnimation *animation = new QPropertyAnimation(ui->frame, "pos");
    QPropertyAnimation *animation2 = new QPropertyAnimation(ui->frame_2, "pos");
    QPropertyAnimation *animation3 = new QPropertyAnimation(m_frameEdit, "pos");
    animation->setDuration(500);
    animation2->setDuration(500);
    animation3->setDuration(500);

    QEventTransition *enterTransition = new QEventTransition(ui->widget, QEvent::MouseButtonRelease);
    enterTransition->setTargetState(s2);
    enterTransition->addAnimation(animation);
    enterTransition->addAnimation(animation2);
    enterTransition->addAnimation(animation3);
    s1->addTransition(enterTransition);

    QEventTransition *leaveTransition1 = new QEventTransition(ui->widget, QEvent::MouseButtonRelease);
    leaveTransition1->setTargetState(s1);
    leaveTransition1->addAnimation(animation);
    leaveTransition1->addAnimation(animation2);
    leaveTransition1->addAnimation(animation3);
    s2->addTransition(leaveTransition1);

    QEventTransition *leaveTransition2 = new QEventTransition(ui->widget, QEvent::MouseButtonRelease);
    leaveTransition2->setTargetState(s1);
    leaveTransition2->addAnimation(animation);
    leaveTransition2->addAnimation(animation2);
    leaveTransition2->addAnimation(animation3);
    s3->addTransition(leaveTransition2);

    QSignalTransition *editTransition = s2->addTransition(ui->pushButtonEdit, SIGNAL(clicked()), s3);
    editTransition->addAnimation(animation);
    editTransition->addAnimation(animation2);
    editTransition->addAnimation(animation3);

    QSignalTransition *cancelTransition = s3->addTransition(m_frameEdit, SIGNAL(canceled()), s2);
    cancelTransition->addAnimation(animation);
    cancelTransition->addAnimation(animation2);
    cancelTransition->addAnimation(animation3);

    m_machine->addState(s1);
    m_machine->addState(s2);
    m_machine->addState(s3);
    m_machine->setInitialState(s1);
    m_machine->start();
}
