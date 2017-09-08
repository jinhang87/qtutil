#ifndef PROGRESSDIALOG_H
#define PROGRESSDIALOG_H

#include <QDialog>

namespace Ui {
class ProgressDialog;
}

class ProgressDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ProgressDialog(const QString &cancelButtonText, int minimum = 0, int maximum = 100, QWidget *parent = 0);
    ~ProgressDialog();

    int value() const;
    void setValue(int progress);
    bool wasCanceled() const;
    bool autoClose() const;
    void setAutoClose(bool autoClose);
    void cancel();

private:
    void reset();
    Ui::ProgressDialog *ui;
    int m_value = 0;
    bool m_wasCanceled = false;
    bool m_autoClose = true;
};

#endif // PROGRESSDIALOG_H
