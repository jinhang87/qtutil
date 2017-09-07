#include "videomenuwidget.h"
#include "ui_videomenuwidget.h"
#include <QPropertyAnimation>
#include <QSignalTransition>
#include <QEventTransition>

VideoMenuWidget::VideoMenuWidget(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::VideoMenuWidget)
{
    ui->setupUi(this);
    machineReset();
    //setStyleSheet("{}");
}

VideoMenuWidget::~VideoMenuWidget()
{
    delete ui;
}

void VideoMenuWidget::machineReset()
{
    m_machine.reset(new QStateMachine(this));
    QState* s1 = new QState();
    QState* s2 = new QState();
    QState* s3 = new QState();

    s1->assignProperty(ui->frame, "pos", QPoint(-ui->frame->width(),0));
    s1->assignProperty(ui->frame_2, "pos", QPoint(this->width()/2-ui->frame_2->width()/2, this->height()));
    s1->assignProperty(ui->frame_3, "pos", QPoint(this->width(), 10));
    s2->assignProperty(ui->frame, "pos", QPoint(-ui->frame->width()+ui->pushButtonMore->width(),0));
    s2->assignProperty(ui->frame_2, "pos", QPoint(this->width()/2-ui->frame_2->width()/2, this->height()-ui->frame_2->height()));
    s2->assignProperty(ui->frame_3, "pos", QPoint(this->width()-ui->frame_3->width(), 10));
    s3->assignProperty(ui->frame, "pos", QPoint(0,0));
    s3->assignProperty(ui->frame_2, "pos", QPoint(this->width()/2-ui->frame_2->width()/2, this->height()-ui->frame_2->height()));
    s3->assignProperty(ui->frame_3, "pos", QPoint(this->width()-ui->frame_3->width(), 10));
    s1->assignProperty(ui->pushButtonMore, "text", QString(">"));
    s2->assignProperty(ui->pushButtonMore, "text", QString(">"));
    s3->assignProperty(ui->pushButtonMore, "text", QString("<"));

    QPropertyAnimation *animation = new QPropertyAnimation(ui->frame, "pos");
    QPropertyAnimation *animation2 = new QPropertyAnimation(ui->frame_2, "pos");
    QPropertyAnimation *animation3 = new QPropertyAnimation(ui->frame_3, "pos");
    animation->setDuration(500);
    animation2->setDuration(500);
    animation3->setDuration(500);

    QSignalTransition *moreTransition = s2->addTransition(ui->pushButtonMore, SIGNAL(clicked()), s3);
    moreTransition->addAnimation(animation);
    moreTransition->addAnimation(animation2);
    moreTransition->addAnimation(animation3);

    QSignalTransition *lessTransition = s3->addTransition(ui->pushButtonMore, SIGNAL(clicked()), s2);
    lessTransition->addAnimation(animation);
    lessTransition->addAnimation(animation2);
    lessTransition->addAnimation(animation3);

    QEventTransition *enterTransition = new QEventTransition(this, QEvent::MouseButtonRelease);
    enterTransition->setTargetState(s2);
    enterTransition->addAnimation(animation);
    enterTransition->addAnimation(animation2);
    enterTransition->addAnimation(animation3);
    s1->addTransition(enterTransition);

    QEventTransition *leaveTransition1 = new QEventTransition(this, QEvent::MouseButtonRelease);
    leaveTransition1->setTargetState(s1);
    leaveTransition1->addAnimation(animation);
    leaveTransition1->addAnimation(animation2);
    leaveTransition1->addAnimation(animation3);
    s2->addTransition(leaveTransition1);

    QEventTransition *leaveTransition2 = new QEventTransition(this, QEvent::MouseButtonRelease);
    leaveTransition2->setTargetState(s1);
    leaveTransition2->addAnimation(animation);
    leaveTransition2->addAnimation(animation2);
    leaveTransition2->addAnimation(animation3);
    s3->addTransition(leaveTransition2);


    m_machine->addState(s1);
    m_machine->addState(s2);
    m_machine->addState(s3);
    m_machine->setInitialState(s1);
    m_machine->start();
}
