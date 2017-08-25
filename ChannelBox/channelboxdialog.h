#ifndef CHANNELBOXDIALOG_H
#define CHANNELBOXDIALOG_H

#include "channelboxwidget.h"
#include <QDialog>
#include <QSharedPointer>
#include <QMultiHash>

namespace Ui {
class ChannelBoxDialog;
}

class ChannelBoxDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChannelBoxDialog(QWidget *parent = 0);
    ~ChannelBoxDialog();

signals:
    //void accepted(const QMultiHash<ChannelFlag, int> &hash);

private:
    void accept() override;
    Ui::ChannelBoxDialog *ui;
};

#endif // CHANNELBOXDIALOG_H
