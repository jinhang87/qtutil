TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

HEADERS += \
    libh/mylib.h \
    libh/mylib_global.h

unix:!macx|win32: LIBS += -L$$PWD/lib/ -lmylib

INCLUDEPATH += $$PWD/lib
DEPENDPATH += $$PWD/lib
