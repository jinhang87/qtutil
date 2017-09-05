#ifndef DIALOGC_H
#define DIALOGC_H

#include <QDialog>

namespace Ui {
class DialogC;
}

class DialogC : public QDialog
{
    Q_OBJECT

public:
    explicit DialogC(QWidget *parent = 0);
    ~DialogC();

private slots:
    void on_pushButton_clicked();

private:
    Ui::DialogC *ui;
};

#endif // DIALOGC_H
