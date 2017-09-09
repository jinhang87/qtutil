#-------------------------------------------------
#
# Project created by QtCreator 2017-09-09T11:06:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VideoOsdConfiguration
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    videoosdcontroldialog.cpp \
    videoosdpaintwidget.cpp

HEADERS  += mainwindow.h \
    videoosdcontroldialog.h \
    videoosdpaintwidget.h

FORMS    += mainwindow.ui \
    videoosdcontroldialog.ui
