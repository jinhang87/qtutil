#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    int i = 0;
    for(i = 0; i < 32; i++){
        QLabel *label = new QLabel(QString::number(i+1), this);
        label->resize(50,50);
        m_listLabels << label;
        ui->gridLayout->addWidget(label, i/9, i%9);
    }
    //m_buttonBox = new QDialogButtonBox(this);
    //m_buttonBox->resize(200,50);
    //m_buttonBox->show();
    //ui->gridLayout->addWidget(m_buttonBox, 32/9, 32%9, 1, 4);
    ui->gridLayout->addWidget(ui->buttonBox, 32/9, 32%9, 1, 4);
}

Widget::~Widget()
{
    delete ui;
}
