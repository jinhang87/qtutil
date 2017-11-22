#ifndef LABELIMAGEDIALOG_H
#define LABELIMAGEDIALOG_H

#include <QDialog>

namespace Ui {
class LabelImageDialog;
}

class LabelImageDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LabelImageDialog(QWidget *parent = 0);
    ~LabelImageDialog();

private:
    Ui::LabelImageDialog *ui;
};

#endif // LABELIMAGEDIALOG_H
