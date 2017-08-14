#ifndef LISTMODEL_H
#define LISTMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include <QStringList>

class ListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit ListModel(const QStringList &strings, QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
signals:

public slots:

private:
    QStringList listString;
};

#endif // LISTMODEL_H
