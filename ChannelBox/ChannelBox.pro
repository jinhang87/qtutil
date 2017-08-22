#-------------------------------------------------
#
# Project created by QtCreator 2017-08-22T11:34:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ChannelBox
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    channelboxmodel.cpp \
    channelboxdialog.cpp \
    channelboxwidget.cpp

HEADERS  += widget.h \
    channelboxmodel.h \
    channelboxdialog.h \
    channelboxwidget.h

FORMS    += widget.ui \
    channelboxdialog.ui \
    channelboxwidget.ui
