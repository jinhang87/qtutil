#ifndef REFLECTIONOBJECT_H
#define REFLECTIONOBJECT_H

#include <QObject>

class ReflectionObject : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int id READ getId WRITE setId)
    Q_PROPERTY(QString name READ getName WRITE setName)
public:
    explicit ReflectionObject(QObject *parent = nullptr);

    Q_INVOKABLE int getId() const;
    Q_INVOKABLE void setId(int value);

    Q_INVOKABLE QString getName() const;
    Q_INVOKABLE void setName(const QString &value);

signals:

public slots:

private:
    int id;
    QString name;
};

#endif // REFLECTIONOBJECT_H
