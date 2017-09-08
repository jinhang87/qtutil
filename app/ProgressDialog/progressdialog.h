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

signals:
    void canceled();

protected:
    void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;

private slots:
    void on_pushButton_clicked();

private:
    void reset();
    Ui::ProgressDialog *ui;
    bool m_wasCanceled = false;
    bool m_autoClose = true;
    bool m_forceHide = false;
};

#endif // PROGRESSDIALOG_H
