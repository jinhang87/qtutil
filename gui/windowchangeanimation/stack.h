#ifndef STACK_H
#define STACK_H

#include <QtWidgets>

class Stack : public QWidget
{
    Q_OBJECT
public:
    explicit Stack(QWidget *parent = 0);
    void wigShow(QWidget *wig, int direct);

signals:


private:
    static const int w=510;
    static const int h=305;

    QPushButton *up;
    QPushButton *down;

    QWidget *wig1;
    QWidget *wig2;
    QWidget *wig3;
    QWidget *wig4;
    QWidget *wig5;
    QWidget *tmpWig;
    QWidget *curWig;


    QWidget *disPlay;
    QWidget *content;

    int cur;
    int timeVal;



private slots:
    void coderSlot(int);
    void upSlot();
    void downSlot();
    void finishSlot();
};

#endif // STACK_H
