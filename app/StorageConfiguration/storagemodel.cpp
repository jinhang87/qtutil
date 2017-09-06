#include "storagemodel.h"

StorageModel::StorageModel(QObject *parent) : QObject(parent)
{
    m_hashStorage.clear();
    StorageInfo info;
    info.current = 500;
    info.total = 1000;
    m_hashStorage.insert(Hardware, info);
}
