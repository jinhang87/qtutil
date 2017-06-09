#ifndef CTESTTIMER_H
#define CTESTTIMER_H

#include <QObject>
#include <QTimer>

class CTestTimer : public QObject
{
    Q_OBJECT
public:
    explicit CTestTimer(QObject *parent = 0);

signals:

public slots:
    void onTimer();

private:
    QTimer *m_ptimer;
};

#endif // CTESTTIMER_H
