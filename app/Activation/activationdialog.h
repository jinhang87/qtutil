#ifndef ACTIVATIONDIALOG_H
#define ACTIVATIONDIALOG_H

#include <QDialog>

namespace Ui {
class ActivationDialog;
}

class ActivationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ActivationDialog(QWidget *parent = 0);
    ~ActivationDialog();

private:
    void onLineEditTextChanged(const QString &text);
    Ui::ActivationDialog *ui;
};

#endif // ACTIVATIONDIALOG_H