#ifndef CHANNELBOXMODEL_H
#define CHANNELBOXMODEL_H

#include <QAbstractListModel>

class ChannelBoxModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit ChannelBoxModel(QObject *parent = 0);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

    QList<int> hashChecked() const;

    int maxNum() const;
    void setMaxNum(int maxNum);

private:
    int m_maxNum = 0;
    QList<int> m_listChecked;
};

#endif // CHANNELBOXMODEL_H
