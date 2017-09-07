#include "activationdialog.h"
#include "ui_activationdialog.h"
#include "passwordvalidator.h"

ActivationDialog::ActivationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ActivationDialog)
{
    ui->setupUi(this);
    QString regString("[^ ]{8,16}");
    QRegExp regExp(regString);
    ui->lineEdit_2->setValidator(new QRegExpValidator(regExp, this));
    ui->lineEdit_3->setValidator(new QRegExpValidator(regExp, this));
    connect(ui->lineEdit_2, &QLineEdit::textChanged, this, &ActivationDialog::onLineEditTextChanged);
}

ActivationDialog::~ActivationDialog()
{
    delete ui;
}

void ActivationDialog::onLineEditTextChanged(const QString &text)
{
    PasswordValidator validator(text);
    PasswordValidator::Level lv = validator.level();
    switch(lv){
    case PasswordValidator::InValid:
    case PasswordValidator::Low:
        ui->frame_high->setStyleSheet("QFrame { border: 1px solid black ; background: #b6070a }");//red
        ui->frame_medium->setStyleSheet("QFrame {  }");
        ui->frame_low->setStyleSheet("QFrame {  }");
        break;
    case PasswordValidator::High:
        ui->frame_low->setStyleSheet("QFrame { border: 1px solid black ; background: #00bc52 }");//green
        ui->frame_medium->setStyleSheet("QFrame {  }");
        ui->frame_high->setStyleSheet("QFrame {  }");
        break;
    case PasswordValidator::Medium:
        ui->frame_medium->setStyleSheet("QFrame { border: 1px solid black ; background: #e28a00 }");//yellow
        ui->frame_low->setStyleSheet("QFrame {  }");
        ui->frame_high->setStyleSheet("QFrame {  }");
        break;
    default:
        break;
    }
}

void ActivationDialog::on_lineEdit_3_textChanged(const QString &arg1)
{
    if(0 != arg1.compare(ui->lineEdit_2->text())){
        ui->label->setText(LEBEL_NOT_SAME_TEXT);
    }else{
        ui->label->setText(LEBEL_DEFAULT_TEXT);
    }
}
