#ifndef MOCKUPPLATFORMINPUTCONTEXTPLUGIN_H
#define MOCKUPPLATFORMINPUTCONTEXTPLUGIN_H

#include "virtualkeyboard_global.h"
#include <qpa/qplatforminputcontextplugin_p.h>

class VIRTUALKEYBOARDSHARED_EXPORT PlatformInputContextPlugin: public QPlatformInputContextPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QPlatformInputContextFactoryInterface.5.1" FILE "Qt5Input.json")

public:
    QStringList keys() const
    {
        return QStringList(QLatin1String("Qt5Input"));
    }
    QPlatformInputContext *create(const QString&, const QStringList&);
};

#endif // MOCKUPPLATFORMINPUTCONTEXTPLUGIN_H
