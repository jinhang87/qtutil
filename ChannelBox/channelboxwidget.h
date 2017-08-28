#ifndef CHANNELBOXWIDGET_H
#define CHANNELBOXWIDGET_H

#include <QWidget>
#include <QButtonGroup>
#include <QHash>
#include <QSharedPointer>
#include <QGridLayout>
#include <QLabel>
#include <QModelIndex>

namespace Ui {
class ChannelBoxWidget;
}

class ChannelBoxModel;
class ChannelBoxWidget : public QWidget
{
    Q_OBJECT

public:
    const int LAEBL_PER_LINE = 9;
    enum SelectedMode { SingleSelectedMode, MultiSelectedMode};
    Q_ENUM(SelectedMode)
    enum ChannelButtonRole { AnalogRole, NetworkRole};
    Q_ENUM(ChannelButtonRole)

public:
    explicit ChannelBoxWidget(QWidget *parent = 0);
    ~ChannelBoxWidget();

    SelectedMode selectedMode() const;
    void setSelectedMode(const SelectedMode &selectedMode);

    QMultiHash<ChannelBoxWidget::ChannelButtonRole, int> checkedRoles();

protected:
    bool eventFilter(QObject *watched, QEvent *event);
    virtual void paintEvent(QPaintEvent *e);

private:
    void setupUi(ChannelButtonRole role);
    void clearChecked();
    Ui::ChannelBoxWidget *ui;
    QButtonGroup* m_ChannelButtonGroup = nullptr;
    QHash<ChannelButtonRole, QSharedPointer<ChannelBoxModel>> m_hashModel;
    QHash<QLabel*, QModelIndex> m_hashWatchedLabels;
    SelectedMode m_selectedMode = SingleSelectedMode;
};

#endif // CHANNELBOXWIDGET_H
