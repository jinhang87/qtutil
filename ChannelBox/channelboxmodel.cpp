#include "channelboxmodel.h"
#include "channelboxdialog.h"
#include <QDebug>

ChannelBoxModel::ChannelBoxModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}

int ChannelBoxModel::rowCount(const QModelIndex &parent) const
{
    //if (!parent.isValid())
        //return 0;
    Q_UNUSED(parent);
    int rowcount = 0;
    if(m_maxAnalogChannelNum>0){
        rowcount++;
    }
    if(m_maxNetworkChannelNum>0){
        rowcount++;
    }
    qDebug() <<"rowcount"<<rowcount;
    return rowcount;
}

int ChannelBoxModel::columnCount(const QModelIndex &parent) const
{
    //if (!parent.isValid())
        //return 0;
    Q_UNUSED(parent);
    return qMax(m_maxAnalogChannelNum, m_maxNetworkChannelNum);
}

QVariant ChannelBoxModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    switch(role){
    case Qt::DisplayRole:
        return QString::number(index.column());
    case Qt::CheckStateRole:
        return false;
    default:
        return QVariant();
    }

    return QVariant();
}

bool ChannelBoxModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!index.isValid())
        return false;

    switch(role){
    case Qt::DisplayRole:
        return false;
    case Qt::CheckStateRole:
        ChannelBoxDialog::ChannelFlag flag;
        if(m_maxAnalogChannelNum==0){
            flag = ChannelBoxDialog::Network;
        }else if(m_maxNetworkChannelNum ==0){
            flag = ChannelBoxDialog::Analog;
        }else{
            flag = (index.row() == 0) ? ChannelBoxDialog::Analog : ChannelBoxDialog::Network;
        }
        if(value.toBool()){
            m_hashChecked.insert(flag, index.column());
        }else{
            m_hashChecked.remove(flag, index.column());
        }
        return true;
    default:
        break;
    }

    return false;
}

QModelIndex ChannelBoxModel::index(int row, int column, const QModelIndex &parent) const
{
    return QAbstractTableModel::index(row, column, parent);
}

int ChannelBoxModel::maxAnalogChannelNum() const
{
    return m_maxAnalogChannelNum;
}

void ChannelBoxModel::setMaxAnalogChannelNum(int maxAnalogChannelNum)
{
    beginResetModel();
    m_maxAnalogChannelNum = maxAnalogChannelNum;
    endResetModel();
}

int ChannelBoxModel::maxNetworkChannelNum() const
{
    return m_maxNetworkChannelNum;
}

void ChannelBoxModel::setMaxNetworkChannelNum(int maxNetworkChannelNum)
{
    beginResetModel();
    m_maxNetworkChannelNum = maxNetworkChannelNum;
    endResetModel();
}

QMultiHash<ChannelBoxDialog::ChannelFlag, int> ChannelBoxModel::hashChecked() const
{
    return m_hashChecked;
}

