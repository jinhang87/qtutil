#include "listitemdelegate.h"

ListItemDelegate::ListItemDelegate(QObject *parent) : QItemDelegate(parent)
{

}

QSize ListItemDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    //return QSize(1,77);
    return QItemDelegate::sizeHint(option, index);
}
