#-------------------------------------------------
#
# Project created by QtCreator 2017-09-08T17:02:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CoverageConfiguration
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    coveragecontroldialog.cpp \
    coveragepaintdialog.cpp \
    coveragepaintwidget.cpp

HEADERS  += mainwindow.h \
    coveragecontroldialog.h \
    coveragepaintdialog.h \
    coveragepaintwidget.h

FORMS    += mainwindow.ui \
    coveragecontroldialog.ui \
    coveragepaintdialog.ui
