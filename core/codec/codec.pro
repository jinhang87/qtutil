#-------------------------------------------------
#
# Project created by QtCreator 2017-11-27T11:27:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = codec
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    utf8dialog.cpp \
    gbkdialog.cpp

HEADERS  += mainwindow.h \
    utf8dialog.h \
    gbkdialog.h

FORMS    += mainwindow.ui \
    utf8dialog.ui \
    gbkdialog.ui

RESOURCES += \
    resource.qrc
