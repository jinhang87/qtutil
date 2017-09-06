#ifndef STORAGESMARTDIALOG_H
#define STORAGESMARTDIALOG_H

#include <QDialog>

namespace Ui {
class StorageSmartDialog;
}

class StorageSmartDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StorageSmartDialog(QWidget *parent = 0);
    ~StorageSmartDialog();

private:
    Ui::StorageSmartDialog *ui;
};

#endif // STORAGESMARTDIALOG_H
