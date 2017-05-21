#include "stack.h"
#include <QDebug>

#define BACK_GROUND QString("background-image:url(")
//#define BACK_GROUND QString("background-image: url(E:\Code\qtutil\animation")



Stack::Stack(QWidget *parent) :
    QWidget(parent)
{
    cur = 1;
    timeVal = 1000;

    disPlay = new QWidget(this);
    disPlay->setStyleSheet(BACK_GROUND + ":/zong.png)");
    disPlay->setFixedSize(800, 480);
qDebug()<<(BACK_GROUND + "zong.png)");
    up = new QPushButton("up", disPlay);
    up->setFixedSize(80, 30);
    up->setStyleSheet("color:white;");
    up->move(15, 120);
    connect(up, SIGNAL(pressed()), this, SLOT(upSlot()));

    down = new QPushButton("down", disPlay);
    down->setFixedSize(80, 30);
    down->setStyleSheet("color:white;");
    down->move(720, 120);
    connect(down, SIGNAL(pressed()), this, SLOT(downSlot()));

    content = new QWidget(disPlay);
    content->setFixedSize(w, h);
    content->setStyleSheet(BACK_GROUND + ":/6.png)");
    content->move(145, 155);
    content->raise();

    wig1 = new QWidget(content);
    wig1->setStyleSheet(BACK_GROUND + ":/1.png)");
    wig1->resize(w, h);

    wig2 = new QWidget(content);
    wig2->setStyleSheet(BACK_GROUND + ":/2.png)");
    wig2->resize(w, h);

    wig3 = new QWidget(content);
    wig3->setStyleSheet(BACK_GROUND + ":/3.png)");
    wig3->resize(w, h);

    wig4 = new QWidget(content);
    wig4->setStyleSheet(BACK_GROUND + ":/4.png)");
    wig4->resize(w, h);

    wig5 = new QWidget(content);
    wig5->setStyleSheet(BACK_GROUND + ":/5.png)");
    wig5->resize(w, h);

    wig1->raise();
    tmpWig = wig1;
}

#define ANIMATION_DUIJIAO

void Stack::wigShow(QWidget *wig, int direct)
{
#ifdef ANIMATION_COVER //覆盖效果
    qDebug() << "ANIMATION_COVER";
    int startx = (direct > 0)? -w : w;
    QPropertyAnimation *animal1= new QPropertyAnimation(wig,"pos");
    animal1->setDuration(timeVal);
    animal1->setStartValue(QPoint(startx,0));
    animal1->setEndValue(QPoint(0,0));
    animal1->setEasingCurve(QEasingCurve::OutCubic);
    wig->raise();
    animal1->start();
#endif
#ifdef ANIMATION_SLIDE //两个界面同时平推
    qDebug() << "ANIMATION_SLIDE";
    int startx = (direct > 0)? -w : w;

    tmpWig = content->childAt(0,0);
    QPropertyAnimation *animal1= new QPropertyAnimation(wig,"pos");
    animal1->setDuration(timeVal);
    animal1->setStartValue(QPoint(startx,0));
    animal1->setEndValue(QPoint(0,0));
    animal1->setEasingCurve(QEasingCurve::OutCubic);

    QPropertyAnimation *animal2= new QPropertyAnimation(tmpWig,"pos");
    animal2->setDuration(timeVal);
    animal2->setStartValue(QPoint(0,0));
    animal2->setEndValue(QPoint(-startx,0));
    animal2->setEasingCurve(QEasingCurve::OutCubic);

    QParallelAnimationGroup *group = new QParallelAnimationGroup;
    group->addAnimation(animal1);
    group->addAnimation(animal2);
    group->start();
    wig->raise();
#endif
#ifdef ANIMATION_ZUO1
    qDebug() << "ANIMATION_ZUO1";
    if(direct > 0){//从左上角慢慢变大出现
        QPropertyAnimation *animal1= new QPropertyAnimation(wig,"size");
        animal1->setDuration(timeVal);
        animal1->setStartValue(QSize(0,0));
        animal1->setEndValue(QSize(w,h));
        animal1->setEasingCurve(QEasingCurve::OutCubic);
        wig->raise();
        animal1->start();
    }else{  //右下角慢慢变大出现
        QPropertyAnimation *animal1= new QPropertyAnimation(wig,"geometry");
        animal1->setDuration(timeVal);
        animal1->setStartValue(QRect(w,h, 0, 0));
        animal1->setEndValue(QRect(0,0, w, h));
        animal1->setEasingCurve(QEasingCurve::OutCubic);
        wig->raise();
        animal1->start();
    }
#endif
#ifdef ANIMATION_ZUO2
    qDebug() << "ANIMATION_ZUO2";
    if(direct > 0){//从左上角慢慢变大出现
        QPropertyAnimation *animal1= new QPropertyAnimation(wig,"size");
        animal1->setDuration(timeVal);
        animal1->setStartValue(QSize(0,0));
        animal1->setEndValue(QSize(w,h));
        animal1->setEasingCurve(QEasingCurve::OutCubic);
        wig->raise();
        animal1->start();
    }else{  //覆盖层从右下角开始慢慢消失显示出要显示的界面
        QWidget *tmp = content->childAt(w-1, h-1);//这个地方必须等到上个动画完毕,否则偶尔会出现混乱
        if(tmp == NULL){
            qDebug()<<"no wig";
            return;
        }
        wig->stackUnder(tmp);  //把要显示的wig放到当前显示的下面
        QPropertyAnimation *animal1= new QPropertyAnimation(tmp,"size");
        animal1->setDuration(timeVal);
        animal1->setStartValue(QSize(w,h));
        animal1->setEndValue(QSize(0,0));
        animal1->setEasingCurve(QEasingCurve::OutCubic);
        animal1->start();
    }
#endif
#ifdef ANIMATION_CENTER
    qDebug() << "ANIMATION_CENTER";
    QPropertyAnimation *animal1= new QPropertyAnimation(wig,"geometry");
    animal1->setDuration(timeVal);
    animal1->setStartValue(QRect(w/2,h/2, 0, 0));
    animal1->setEndValue(QRect(0,0, w, h));
    wig->raise();
    animal1->start();
#endif
#ifdef ANIMATION_CENTER2
    qDebug() << "ANIMATION_CENTER2";
    QPropertyAnimation *animal1= new QPropertyAnimation(wig,"geometry");
    animal1->setDuration(timeVal);
    animal1->setStartValue(QRect(w/2,h/2, 0, 0));
    animal1->setEndValue(QRect(0,0, w, h));
    animal1->setEasingCurve(QEasingCurve::OutCubic);
    wig->raise();
    animal1->start();
#endif
#ifdef ANIMATION_DUIJIAO //对角变化
    qDebug() << "ANIMATION_DUIJIAO";
    tmpWig = content->childAt(0,0);
    QPropertyAnimation *animal1= new QPropertyAnimation(wig,"geometry");
    animal1->setDuration(timeVal);
    (direct > 0)? animal1->setStartValue(QRect(0,0, 0, 0)):animal1->setStartValue(QRect(w,h, 0, 0));
    (direct > 0)? animal1->setEndValue(QRect(0,0, w, h)):animal1->setEndValue(QRect(0,0, w, h));

    QPropertyAnimation *animal2= new QPropertyAnimation(tmpWig,"geometry");
    animal2->setDuration(timeVal);
    (direct > 0)? animal2->setStartValue(QRect(0,0, w, h)):animal2->setStartValue(QRect(0,0, w, h));
    (direct > 0)? animal2->setEndValue(QRect(w,h, 0, 0)):animal2->setEndValue(QRect(0,0, 0, 0));

    QParallelAnimationGroup *group = new QParallelAnimationGroup;
    group->addAnimation(animal1);
    group->addAnimation(animal2);
    group->start();
    wig->raise();
#endif
}

void Stack::finishSlot()
{
#ifdef TEST //覆盖效果
    tmpWig = curWig;
#endif
}

void Stack::coderSlot(int direct)
{
    if(direct > 0){  //右旋
        switch (cur) {
        case 1:
            wigShow(wig2, direct);
            break;
        case 2:
            wigShow(wig3, direct);
            break;
        case 3:
            wigShow(wig4, direct);
            break;
        case 4:
            wigShow(wig5, direct);
            break;
        default:
            return;
            break;
        }
        cur++;
    }else {
        switch (cur) {
        case 5:
            wigShow(wig4, direct);
            break;
        case 4:
            wigShow(wig3, direct);
            break;
        case 3:
            wigShow(wig2, direct);
            break;
        case 2:
            wigShow(wig1, direct);
            break;
        default:
            return;
            break;
        }
        cur--;
    }
}

void Stack::downSlot()
{
    coderSlot(1);
}


void Stack::upSlot()
{
    qDebug() << "upSlot";
    coderSlot(-1);
}

