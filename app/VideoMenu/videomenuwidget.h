#ifndef VIDEOMENUWIDGET_H
#define VIDEOMENUWIDGET_H

#include <QDialog>
#include <QSharedPointer>
#include <QStateMachine>

namespace Ui {
class VideoMenuWidget;
}

class VideoMenuWidget : public QDialog
{
    Q_OBJECT

public:
    explicit VideoMenuWidget(QDialog *parent = 0);
    ~VideoMenuWidget();
protected:
    void paintEvent(QPaintEvent *event);
private:
    void machineReset();
    Ui::VideoMenuWidget *ui;
    QSharedPointer<QStateMachine> m_machine;
};

#endif // VIDEOMENUWIDGET_H
