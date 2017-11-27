#ifndef GBKDIALOG_H
#define GBKDIALOG_H

#include <QDialog>

namespace Ui {
class GbkDialog;
}

class GbkDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GbkDialog(QWidget *parent = 0);
    ~GbkDialog();

private:
    Ui::GbkDialog *ui;
};

#endif // GBKDIALOG_H
