#ifndef VIDEOOSDCONTROLDIALOG_H
#define VIDEOOSDCONTROLDIALOG_H

#include <QDialog>

namespace Ui {
class VideoOsdControlDialog;
}

class VideoOsdControlDialog : public QDialog
{
    Q_OBJECT

public:
    explicit VideoOsdControlDialog(QWidget *parent = 0);
    ~VideoOsdControlDialog();

private:
    Ui::VideoOsdControlDialog *ui;
};

#endif // VIDEOOSDCONTROLDIALOG_H
