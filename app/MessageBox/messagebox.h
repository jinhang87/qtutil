#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class MessageBox;
}

class MessageBox : public QDialog
{
    Q_OBJECT

public:

    enum Icon { NoIcon, Question, Information, Warning, Critical };
    Q_ENUM(Icon)
    explicit MessageBox(Icon icon, const QString &text, QMessageBox::StandardButtons buttons = QMessageBox::NoButton, QWidget *parent = 0);
    ~MessageBox();
    static int information(QWidget *parent, const QString& text,
                           QMessageBox::StandardButtons buttons = QMessageBox::Ok,
                           QMessageBox::StandardButton defaultButton = QMessageBox::NoButton);
    static int question(QWidget *parent, const QString& text,
                           QMessageBox::StandardButtons buttons = QMessageBox::Ok,
                           QMessageBox::StandardButton defaultButton = QMessageBox::NoButton);
    static int critical(QWidget *parent, const QString& text,
                           QMessageBox::StandardButtons buttons = QMessageBox::Ok,
                           QMessageBox::StandardButton defaultButton = QMessageBox::NoButton);


private:
    Ui::MessageBox *ui;
};

#endif // MESSAGEBOX_H
