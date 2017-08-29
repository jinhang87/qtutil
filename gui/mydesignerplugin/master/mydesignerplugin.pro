CONFIG      += plugin
TARGET      = $$qtLibraryTarget(mydesignerpluginplugin)
TEMPLATE    = lib

#DESTDIR = D:\hik_project\qt_prj\bin\hello\plugins

HEADERS     = mydesignerpluginplugin.h
SOURCES     = mydesignerpluginplugin.cpp
RESOURCES   = icons.qrc
LIBS        += -L. 

greaterThan(QT_MAJOR_VERSION, 4) {
    QT += designer
} else {
    CONFIG += designer
}

target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS    += target

include(mydesignerplugin.pri)
