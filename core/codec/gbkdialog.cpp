#include "gbkdialog.h"
#include "ui_gbkdialog.h"

//���ļ�ΪGBK���룬ʹ��QtCreator����GBK���룬Ȼ��༭�ļ�����notepad++���½ǲ鿴���뷽ʽ

GbkDialog::GbkDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GbkDialog)
{
    ui->setupUi(this);
    setStyleSheet("QLabel { border-image: url(:/-click-.png); }"
                  "QLabel { border-image: url(:/����-click-.png); }");
}

GbkDialog::~GbkDialog()
{
    delete ui;
}
