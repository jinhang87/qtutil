#ifndef DIALOGB_H
#define DIALOGB_H

#include <QDialog>

namespace Ui {
class DialogB;
}

class DialogB : public QDialog
{
    Q_OBJECT

public:
    explicit DialogB(QWidget *parent = 0);
    ~DialogB();

private slots:
    void on_pushButton_clicked();

private:
    Ui::DialogB *ui;
};

#endif // DIALOGB_H
