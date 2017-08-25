#ifndef CHANNELBOXWIDGET_H
#define CHANNELBOXWIDGET_H

#include <QWidget>
#include <QButtonGroup>
#include <QHash>
#include <QSharedPointer>
#include <QGridLayout>

namespace Ui {
class ChannelBoxWidget;
}

class ChannelBoxModel;
class ChannelBoxWidget : public QWidget
{
    Q_OBJECT

public:
    const int LAEBL_PER_LINE = 9;
    enum Mode { SingleSelectedMode, MultiSelectedMode};
    Q_ENUM(Mode)
    enum ChannelButtonRole { AnalogRole, NetworkRole};
    Q_ENUM(ChannelButtonRole)

public:
    explicit ChannelBoxWidget(QWidget *parent = 0);
    ~ChannelBoxWidget();

protected:
    bool eventFilter(QObject *watched, QEvent *event);
    virtual void paintEvent(QPaintEvent *e);

private:
    void setupUi(ChannelButtonRole role);
    Ui::ChannelBoxWidget *ui;
    QButtonGroup* m_ChannelButtonGroup = nullptr;
    QHash<ChannelButtonRole, QSharedPointer<ChannelBoxModel>> m_hashModel;
};

#endif // CHANNELBOXWIDGET_H
