#include "gbkdialog.h"
#include "ui_gbkdialog.h"

//本文件为GBK编码，使用QtCreator配置GBK编码，然后编辑文件，用notepad++右下角查看编码方式

GbkDialog::GbkDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GbkDialog)
{
    ui->setupUi(this);
    setStyleSheet("QLabel { border-image: url(:/-click-.png); }"
                  "QLabel { border-image: url(:/剪切-click-.png); }");
}

GbkDialog::~GbkDialog()
{
    delete ui;
}
