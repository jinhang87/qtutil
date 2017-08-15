#-------------------------------------------------
#
# Project created by QtCreator 2017-08-14T16:06:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WeekPlaner
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    daytrack.cpp \
    sliderbutton.cpp \
    daytrackgroup.cpp \
    timetip.cpp

HEADERS  += mainwindow.h \
    daytrack.h \
    sliderbutton.h \
    daytrackgroup.h \
    timetip.h

FORMS    += mainwindow.ui
