#include "utf8dialog.h"
#include "ui_utf8dialog.h"
#include <QDebug>

//方法一：
//1）QtCreator 配置：工具->选项->文件编码->默认编码->UTF8
//2）编辑文件后保存的文件时UTF8编码方式
//3）字符串前面加u8,c++11方式

#define QLABEL_CN u8"QLabel#labelcn{ border-image: url(:/剪切-click-.png);}"
Utf8Dialog::Utf8Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Utf8Dialog)
{
    ui->setupUi(this);
    setStyleSheet(u8"QLabel#labelen{ border-image: url(:/-click-.png);}"
                  u8"QLabel#labelcn{ border-image: url(:/剪切-click-.png);}");
    qDebug() << QLABEL_CN << QString::fromUtf8(QLABEL_CN);
}

Utf8Dialog::~Utf8Dialog()
{
    delete ui;
}
