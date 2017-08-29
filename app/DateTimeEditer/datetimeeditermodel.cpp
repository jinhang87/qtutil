#include "datetimeeditermodel.h"

DateTimeEditerModel::DateTimeEditerModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

int DateTimeEditerModel::rowCount(const QModelIndex &parent) const
{
//    if (!parent.isValid())
//        return 0;

    // FIXME: Implement me!
    Q_UNUSED(parent);
    return m_maxNum;
}

QVariant DateTimeEditerModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    switch(role){
    case Qt::DisplayRole:
        return QString::number(index.row()+1);
    case Qt::CheckStateRole:
        return (m_checked == index.row())?true:false;
    default:
        return QVariant();
    }

    return QVariant();
}

bool DateTimeEditerModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!index.isValid())
        return false;

    switch(role){
    case Qt::DisplayRole:
        return false;
    case Qt::CheckStateRole:
        if(value.toBool()){
            m_checked = index.row();
        }else{
            m_checked = (m_checked == index.row()) ? 0 : m_checked;
        }

        return true;
    default:
        break;
    }

    return false;
}

int DateTimeEditerModel::maxNum() const
{
    return m_maxNum;
}

void DateTimeEditerModel::setMaxNum(int maxNum)
{
    beginResetModel();
    m_maxNum = maxNum;
    m_checked = 0;
    endResetModel();
}

int DateTimeEditerModel::checked() const
{
    return m_checked;
}

void DateTimeEditerModel::clearChecked()
{
    m_checked = 0;
}
