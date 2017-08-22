#ifndef CHANNELBOXMODEL_H
#define CHANNELBOXMODEL_H

#include <QAbstractTableModel>

enum ChannelFlag : int;
class ChannelBoxModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit ChannelBoxModel(QObject *parent = 0);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;

    int maxAnalogChannelNum() const;
    void setMaxAnalogChannelNum(int maxAnalogChannelNum);

    int maxNetworkChannelNum() const;
    void setMaxNetworkChannelNum(int maxNetworkChannelNum);

    QMultiHash<ChannelFlag, int> hashChecked() const;

private:
    int m_maxAnalogChannelNum = 0;
    int m_maxNetworkChannelNum = 0;
    QMultiHash<ChannelFlag, int> m_hashChecked;

};

#endif // CHANNELBOXMODEL_H
