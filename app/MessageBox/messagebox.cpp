#include "messagebox.h"
#include "ui_messagebox.h"

MessageBox::MessageBox(Icon icon, const QString &text, QMessageBox::StandardButtons buttons, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MessageBox)
{
    ui->setupUi(this);
    ui->buttonBox->setStyleSheet("QPushButton { min-width: 150px ; min-height: 60px}");
    ui->buttonBox->setStandardButtons(QDialogButtonBox::StandardButtons(int(buttons)));

    ui->label_2->setText(text);
}

MessageBox::~MessageBox()
{
    delete ui;
}
