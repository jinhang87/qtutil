#-------------------------------------------------
#
# Project created by QtCreator 2017-09-21T20:15:04
#
#-------------------------------------------------

QT       -= core gui

TARGET = mylib
TEMPLATE = lib

DEFINES += MYLIB_LIBRARY

SOURCES += mylib.cpp

HEADERS += mylib.h\
        mylib_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
