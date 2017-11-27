#ifndef UTF8DIALOG_H
#define UTF8DIALOG_H

#include <QDialog>

namespace Ui {
class Utf8Dialog;
}

class Utf8Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Utf8Dialog(QWidget *parent = 0);
    ~Utf8Dialog();

private:
    Ui::Utf8Dialog *ui;
};

#endif // UTF8DIALOG_H
