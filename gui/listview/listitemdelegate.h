#ifndef LISTITEMDELEGATE_H
#define LISTITEMDELEGATE_H

#include <QItemDelegate>

class ListItemDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    explicit ListItemDelegate(QObject *parent = nullptr);

    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override;

signals:

public slots:
};

#endif // LISTITEMDELEGATE_H
