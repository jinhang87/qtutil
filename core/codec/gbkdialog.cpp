#include "gbkdialog.h"
#include "ui_gbkdialog.h"
#include <QDebug>
//本文件为GBK编码，使用QtCreator配置GBK编码，然后编辑文件，用notepad++右下角查看编码方式

#define QLABLE_CN u8"QLabel { border-image: url(:/剪切-click-.png);"

GbkDialog::GbkDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GbkDialog)
{
    ui->setupUi(this);
    setStyleSheet(u8"QLabel#labelen { border-image: url(:/-click-.png); }"
                  u8"QLabel#labelcn { border-image: url(:/剪切-click-.png); }");
    qDebug() << QLABLE_CN;
}

GbkDialog::~GbkDialog()
{
    delete ui;
}
