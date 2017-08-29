#ifndef SERVICE_H
#define SERVICE_H

#include <QObject>
#include <QVariantMap>

class Service : public QObject
{
    Q_OBJECT
public:
    explicit Service(QObject *parent = nullptr);
    QVariantMap process(const QVariantMap &request);

signals:

public slots:

private:
    Q_INVOKABLE QVariantMap processSetConfig(const QVariantMap &request);
    Q_INVOKABLE QVariantMap processGetConfig(const QVariantMap &request);
    Q_INVOKABLE QVariantMap processGetJson(const QVariantMap &request);
    QVariantMap m_settings;
};

#endif // SERVICE_H
