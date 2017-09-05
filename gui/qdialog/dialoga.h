#ifndef DIALOGA_H
#define DIALOGA_H

#include <QDialog>

namespace Ui {
class DialogA;
}

class DialogA : public QDialog
{
    Q_OBJECT

public:
    explicit DialogA(QWidget *parent = 0);
    ~DialogA();

private slots:
    void on_pushButton_clicked();

private:
    Ui::DialogA *ui;
};

#endif // DIALOGA_H
