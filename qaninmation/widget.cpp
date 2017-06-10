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

    pAnimation = new QPropertyAnimation();
    pAnimation->setTargetObject(this);
    pAnimation->setPropertyName("opacity");
    pAnimation->setDuration(500);
    pAnimation->setKeyValueAt(0, 0);
    pAnimation->setKeyValueAt(1, 1);
    //pAnimation->setEasingCurve(QEasingCurve::OutBounce);  // 缓和曲线风格

    pAnimation2 = new QPropertyAnimation();
    pAnimation2->setTargetObject(this);
    pAnimation2->setPropertyName("opacity");
    pAnimation2->setDuration(500);
    pAnimation2->setKeyValueAt(0, 1);
    pAnimation2->setKeyValueAt(1, 0);
    //pAnimation2->setEasingCurve(QEasingCurve::OutBounce);  // 缓和曲线风格
    connect(ui->pushButton_2, SIGNAL(clicked(bool)), this, SLOT(onBtnClicked()));
}

void Widget::onBtnClicked()
{
    static int count = 0;
    if(count++%2 == 0){
        pAnimation->start();
    }else{
        pAnimation2->start();
    }
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
