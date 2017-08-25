#include "channelboxmodel.h"
#include "channelboxdialog.h"
#include <QDebug>

ChannelBoxModel::ChannelBoxModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

int ChannelBoxModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_maxNum;
}

QVariant ChannelBoxModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    switch(role){
    case Qt::DisplayRole:
        return QString::number(index.row()+1);
    case Qt::CheckStateRole:
        return (m_listChecked.contains(index.row()))?true:false;
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
        if(value.toBool()){
            m_listChecked.append(index.row());
        }else{
            m_listChecked.removeAll(index.row());
        }
        return true;
    default:
        break;
    }

    return false;
}

QList<int> ChannelBoxModel::hashChecked() const
{
    return m_listChecked;
}

int ChannelBoxModel::maxNum() const
{
    return m_maxNum;
}

void ChannelBoxModel::setMaxNum(int maxNum)
{
    beginResetModel();
    m_maxNum = maxNum;
    m_listChecked.clear();
    endResetModel();
}

