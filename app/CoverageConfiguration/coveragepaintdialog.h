#ifndef COVERAGEPAINTDIALOG_H
#define COVERAGEPAINTDIALOG_H

#include <QDialog>

namespace Ui {
class CoveragePaintDialog;
}

class CoveragePaintDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CoveragePaintDialog(QWidget *parent = 0);
    ~CoveragePaintDialog();
protected:
    void paintEvent(QPaintEvent *event);

private:
    Ui::CoveragePaintDialog *ui;
};

#endif // COVERAGEPAINTDIALOG_H
