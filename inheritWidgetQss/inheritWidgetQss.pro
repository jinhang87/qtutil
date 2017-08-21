#-------------------------------------------------
#
# Project created by QtCreator 2017-08-16T21:57:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = inheritWidgetQss
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    subwidget.cpp \
    dialog.cpp

HEADERS  += widget.h \
    subwidget.h \
    dialog.h

FORMS    += widget.ui \
    dialog.ui
