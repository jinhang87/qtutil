#ifndef DATETIMEEDITERMODEL_H
#define DATETIMEEDITERMODEL_H

#include <QAbstractListModel>

class DateTimeEditerModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit DateTimeEditerModel(QObject *parent = 0);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

    int maxNum() const;
    void setMaxNum(int maxNum);

    int checked() const;
    void clearChecked();

private:
    int m_maxNum = 0;
    int m_checked = 0;
};

#endif // DATETIMEEDITERMODEL_H
