TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/ -lmylib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/ -lmylibd
else:unix:!macx: LIBS += -L$$PWD/lib/ -lmylib

INCLUDEPATH += $$PWD/lib
DEPENDPATH += $$PWD/lib

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/lib/libmylib.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/lib/libmylibd.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/lib/mylib.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/lib/mylibd.lib
else:unix:!macx: PRE_TARGETDEPS += $$PWD/lib/libmylib.a

HEADERS += \
    libh/mylib.h \
    libh/mylib_global.h
