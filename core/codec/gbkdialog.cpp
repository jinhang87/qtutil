#include "gbkdialog.h"
#include "ui_gbkdialog.h"
#include <QDebug>
//���ļ�ΪGBK���룬ʹ��QtCreator����GBK���룬Ȼ��༭�ļ�����notepad++���½ǲ鿴���뷽ʽ

#define QLABLE_CN u8"QLabel { border-image: url(:/����-click-.png);"

GbkDialog::GbkDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GbkDialog)
{
    ui->setupUi(this);
    setStyleSheet(u8"QLabel#labelen { border-image: url(:/-click-.png); }"
                  u8"QLabel#labelcn { border-image: url(:/����-click-.png); }");
    qDebug() << QLABLE_CN;
}

GbkDialog::~GbkDialog()
{
    delete ui;
}
