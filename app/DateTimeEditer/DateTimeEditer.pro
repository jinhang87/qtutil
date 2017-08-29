#-------------------------------------------------
#
# Project created by QtCreator 2017-08-29T18:34:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DateTimeEditer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    datetimeediterdialog.cpp \
    datetimeediterwidget.cpp \
    datetimeeditermodel.cpp

HEADERS  += mainwindow.h \
    datetimeediterdialog.h \
    datetimeediterwidget.h \
    datetimeeditermodel.h

FORMS    += mainwindow.ui \
    datetimeediterdialog.ui \
    datetimeediterwidget.ui
