#-------------------------------------------------
#
# Project created by QtCreator 2017-05-15T21:09:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = threadworker
TEMPLATE = app
#DEFINES += USE_QPOINTER

SOURCES += main.cpp\
        mainwindow.cpp \
    worker.cpp

HEADERS  += mainwindow.h \
    worker.h

FORMS    += mainwindow.ui
