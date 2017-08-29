#include "ctesttimer.h"
#include <QDebug>

CTestTimer::CTestTimer(QObject *parent) : QObject(parent)
{
    m_ptimer = new QTimer(0);
    m_ptimer->setInterval(2*1000);
    m_ptimer->setSingleShot(true);
    connect(m_ptimer, SIGNAL(timeout()), this, SLOT(onTimer()));
    m_ptimer->start();
    qDebug()<<"Timer start";
}


void CTestTimer::onTimer()
{
    qDebug()<<"on Timer";
}

