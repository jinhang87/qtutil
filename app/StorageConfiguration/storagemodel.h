#ifndef STORAGEMODEL_H
#define STORAGEMODEL_H

#include <QObject>
#include <QMultiHash>

class StorageInfo{
public:
    int current;
    int total;
//    smart smart;
};

class StorageModel : public QObject
{
    Q_OBJECT
public:
    enum StorageMedium { Hardware, SDCard, FireBox};
    Q_ENUM(StorageMedium)

    explicit StorageModel(QObject *parent = 0);

signals:

public slots:

private:
    QMultiHash<StorageMedium, StorageInfo> m_hashStorage;
};

#endif // STORAGEMODEL_H
