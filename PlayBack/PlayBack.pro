#-------------------------------------------------
#
# Project created by QtCreator 2017-09-09T12:49:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PlayBack
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    playbackdialog.cpp \
    playbackeditbar.cpp

HEADERS  += mainwindow.h \
    playbackdialog.h \
    playbackeditbar.h

FORMS    += mainwindow.ui \
    playbackdialog.ui \
    playbackeditbar.ui
