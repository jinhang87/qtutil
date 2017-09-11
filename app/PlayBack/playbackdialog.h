#ifndef PLAYBACKDIALOG_H
#define PLAYBACKDIALOG_H

#include <QDialog>
#include <QSharedPointer>
#include <QStateMachine>
#include <QFrame>

namespace Ui {
class PlayBackDialog;
}

class PlayBackEditBar;
class PlayBackDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PlayBackDialog(QWidget *parent = 0);
    ~PlayBackDialog();

private:
    void machineReset();
    Ui::PlayBackDialog *ui;
    QSharedPointer<QStateMachine> m_machine;
    PlayBackEditBar *m_frameEdit;
};

#endif // PLAYBACKDIALOG_H
