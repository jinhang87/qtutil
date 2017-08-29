#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QAbstractItemModel>

class model : public QAbstractItemModel
{
    Q_OBJECT
public:
    explicit model(QObject *parent = nullptr);

signals:

public slots:
};

#endif // MODEL_H
