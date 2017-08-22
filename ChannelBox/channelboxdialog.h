#ifndef CHANNELBOXDIALOG_H
#define CHANNELBOXDIALOG_H

#include <QDialog>
#include <QSharedPointer>
#include <QMultiHash>

namespace Ui {
class ChannelBoxDialog;
}

class ChannelBoxModel;
class ChannelBoxDialog : public QDialog
{
    Q_OBJECT

public:
    enum Mode { SingleSelected, MultiSelected};
    Q_ENUM(Mode)
    enum ChannelFlag { Analog, Network};
    Q_ENUM(ChannelFlag)

    explicit ChannelBoxDialog(QWidget *parent = 0);
    ~ChannelBoxDialog();

    ChannelBoxDialog::Mode mode() const;
    void setMode(const Mode &mode);

signals:
    void accepted(const QMultiHash<ChannelFlag, int> &hash);

private:
    void accept() override;
    Ui::ChannelBoxDialog *ui;
    QSharedPointer<ChannelBoxModel> m_model;
    Mode m_mode;
};

#endif // CHANNELBOXDIALOG_H
