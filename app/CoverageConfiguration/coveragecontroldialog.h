#ifndef COVERAGECONTROLDIALOG_H
#define COVERAGECONTROLDIALOG_H

#include <QDialog>

namespace Ui {
class CoverageControlDialog;
}

class CoverageControlDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CoverageControlDialog(QWidget *parent = 0);
    ~CoverageControlDialog();
protected:
    void paintEvent(QPaintEvent *event);
private slots:
    void on_pushButtonNew_clicked();

private:
    Ui::CoverageControlDialog *ui;
};

#endif // COVERAGECONTROLDIALOG_H
