#ifndef CHANNELBOXWIDGET_H
#define CHANNELBOXWIDGET_H

#include <QWidget>
#include <QAbstractItemModel>
#include <QButtonGroup>

namespace Ui {
class ChannelBoxWidget;
}

enum ChannelFlag : int;
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

protected:
    bool eventFilter(QObject *watched, QEvent *event);
    virtual void paintEvent(QPaintEvent *e);

private:
    void setupUi();
    Ui::ChannelBoxWidget *ui;
    QAbstractItemModel *m_model = nullptr;
    QButtonGroup* m_btnGroupChannelFlag = nullptr;
};

#endif // CHANNELBOXWIDGET_H
