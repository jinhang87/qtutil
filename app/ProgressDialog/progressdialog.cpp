#include "progressdialog.h"
#include "ui_progressdialog.h"
#include <QDebug>

ProgressDialog::ProgressDialog(const QString &cancelButtonText, int minimum, int maximum, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProgressDialog)
{
    ui->setupUi(this);
    ui->progressBar->setRange(minimum, maximum);
}

ProgressDialog::~ProgressDialog()
{
    delete ui;
}

int ProgressDialog::value() const
{
    return ui->progressBar->value();
}

void ProgressDialog::setValue(int progress)
{
    ui->progressBar->setValue(progress);
    qDebug() << progress;
    if (isModal())
        QApplication::processEvents();

    if (progress >= ui->progressBar->maximum())
        reset();
}

bool ProgressDialog::wasCanceled() const
{
    return m_wasCanceled;
}

bool ProgressDialog::autoClose() const
{
    return m_autoClose;
}

void ProgressDialog::setAutoClose(bool autoClose)
{
    m_autoClose = autoClose;
}

void ProgressDialog::cancel()
{
    m_forceHide = true;
    reset();
    m_forceHide = false;
    m_wasCanceled = true;
}

void ProgressDialog::closeEvent(QCloseEvent *event)
{
    emit canceled();
    QDialog::closeEvent(event);
}

void ProgressDialog::reset()
{
    if(m_autoClose || m_forceHide){
        hide();
    }
}


void ProgressDialog::on_pushButton_clicked()
{
    cancel();
}
