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
    const QString LEBEL_DEFAULT_TEXT = QObject::tr("8-16, two combinations of Numbers, letters, and special characters");
    const QString LEBEL_NOT_SAME_TEXT = QObject::tr("two password not same");
    explicit ActivationDialog(QWidget *parent = 0);
    ~ActivationDialog();

private slots:
    void on_lineEdit_3_textChanged(const QString &arg1);

private:
    void onLineEditTextChanged(const QString &text);
    Ui::ActivationDialog *ui;
};

#endif // ACTIVATIONDIALOG_H
