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
        break;
    case PasswordValidator::High:

        break;
    case PasswordValidator::Medium:
        break;
    case PasswordValidator::Low:
        break;
    default:
        break;
    }
}
