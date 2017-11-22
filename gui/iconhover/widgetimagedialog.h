#ifndef WIDGETIMAGEDIALOG_H
#define WIDGETIMAGEDIALOG_H

#include <QDialog>

namespace Ui {
class WidgetImageDialog;
}

class WidgetImageDialog : public QDialog
{
    Q_OBJECT

public:
    explicit WidgetImageDialog(QWidget *parent = 0);
    ~WidgetImageDialog();

private slots:
    void on_pushButtonChange_clicked();
    void onWidgetImageChange();

private:
    Ui::WidgetImageDialog *ui;
};

#endif // WIDGETIMAGEDIALOG_H
