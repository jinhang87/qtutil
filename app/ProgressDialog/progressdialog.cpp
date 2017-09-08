#include "progressdialog.h"
#include "ui_progressdialog.h"

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
    return m_value;
}

void ProgressDialog::setValue(int progress)
{
    m_value = progress;
    ui->progressBar->setValue(progress);

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
    reset();
}

void ProgressDialog::reset()
{
    if(m_autoClose){
        hide();
    }
}

