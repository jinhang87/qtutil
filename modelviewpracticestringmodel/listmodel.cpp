#include "listmodel.h"

ListModel::ListModel(const QStringList &strings, QObject *parent) : QAbstractListModel(parent), listString(strings)
{

}

int ListModel::rowCount(const QModelIndex &parent) const
{
    return listString.count();
}

QVariant ListModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();
    if(index.row() >= listString.size())
        return QVariant();
    if(role == Qt::DisplayRole)
        return listString.at(index.row());
    else
        return QVariant();
}

QVariant ListModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role != Qt::DisplayRole)
        return QVariant();
    if(orientation == Qt::Horizontal)
        return QString("Column %1").arg(section);
    else
        return QString("Row %1").arg(section);
}
