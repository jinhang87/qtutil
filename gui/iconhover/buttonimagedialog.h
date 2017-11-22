#ifndef BUTTONIMAGEDIALOG_H
#define BUTTONIMAGEDIALOG_H

#include <QDialog>

namespace Ui {
class ButtonImageDialog;
}

class ButtonImageDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ButtonImageDialog(QWidget *parent = 0);
    ~ButtonImageDialog();

private:
    Ui::ButtonImageDialog *ui;
};

#endif // BUTTONIMAGEDIALOG_H
