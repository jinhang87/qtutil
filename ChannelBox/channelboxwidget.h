#ifndef CHANNELBOXWIDGET_H
#define CHANNELBOXWIDGET_H

#include <QWidget>
#include <QAbstractItemModel>
#include <QButtonGroup>

namespace Ui {
class ChannelBoxWidget;
}

class ChannelBoxWidget : public QWidget
{
    Q_OBJECT

public:
    const int LAEBL_PER_LINE = 9;
public:
    explicit ChannelBoxWidget(QWidget *parent = 0);
    ~ChannelBoxWidget();

    QAbstractItemModel *model() const;
    void setModel(QAbstractItemModel *model);

private:
    void setupUi();
    Ui::ChannelBoxWidget *ui;
    QAbstractItemModel *m_model = nullptr;
    QButtonGroup* m_btnGroupChannelFlag = nullptr;
};

#endif // CHANNELBOXWIDGET_H
