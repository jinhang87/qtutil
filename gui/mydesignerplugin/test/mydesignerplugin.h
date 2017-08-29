#ifndef MYDESIGNERPLUGIN_H
#define MYDESIGNERPLUGIN_H


#include <QtWidgets>
#include <QtDesigner/QtDesigner>

QT_BEGIN_NAMESPACE


class QDESIGNER_WIDGET_EXPORT MyDesignerPlugin : public QWidget
{
    Q_OBJECT

public:
    MyDesignerPlugin(QWidget *parent = 0);
};

QT_END_NAMESPACE

#endif
