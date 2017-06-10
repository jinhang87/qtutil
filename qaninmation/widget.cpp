#include "widget.h"
#include "ui_widget.h"
#include <QPropertyAnimation>
#include <QDebug>
#include <QGraphicsOpacityEffect>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
#if 0
    QPropertyAnimation *pAnimation = new QPropertyAnimation(ui->pushButton, "geometry");
    pAnimation->setDuration(1000);
    pAnimation->setStartValue(QRect(0, 0, 75, 25));
    pAnimation->setEndValue(QRect(200, 130, 75, 25));
    pAnimation->setEasingCurve(QEasingCurve::OutBounce);  // 缓和曲线风格
    pAnimation->start();
#endif

#if 1
    QPropertyAnimation *pAnimation = new QPropertyAnimation();
    pAnimation->setTargetObject(this);
    pAnimation->setPropertyName("opacity");
    pAnimation->setDuration(1000);
    pAnimation->setKeyValueAt(0, 0);
    pAnimation->setKeyValueAt(0.5, 1);
    pAnimation->setKeyValueAt(1, 0);
    pAnimation->setLoopCount(-1); //永远运行，直到stop
    connect(ui->pushButton_2, SIGNAL(clicked(bool)), pAnimation, SLOT(start()));
#endif

}

int Widget::alpha() const
{
    return m_nAlpha;
}

void Widget::setAlpha(const int alpha)
{
    m_nAlpha = alpha;
}

qreal Widget::opacity() const
{
    return m_fOpacity;
}

void Widget::setOpacity(const qreal opacity)
{
    m_fOpacity = opacity;
    //qDebug() << opacity;
    QGraphicsOpacityEffect *effect = new QGraphicsOpacityEffect(this);
    effect->setOpacity(opacity);
    ui->pushButton->setGraphicsEffect(effect);
}


Widget::~Widget()
{
    delete ui;
}
