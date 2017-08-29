#ifndef DATETIMEEDITERDIALOG_H
#define DATETIMEEDITERDIALOG_H

#include <QDialog>

namespace Ui {
class DateTimeEditerDialog;
}

class DateTimeEditerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DateTimeEditerDialog(QWidget *parent = 0);
    ~DateTimeEditerDialog();

private:
    Ui::DateTimeEditerDialog *ui;
};

#endif // DATETIMEEDITERDIALOG_H
