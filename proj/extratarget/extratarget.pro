QT += core
QT -= gui

CONFIG += c++11

TARGET = extratarget
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp


mybuild.target=mybuild
SRCTARGET = $$quote($$PWD/lib/mylib.dll)
DSTTARGET = $$quote($$PWD)
win32:SRCTARGET ~= s,/,\\,g
win32:DSTTARGET ~= s,/,\\,g
mybuild.commands=${COPY} $$SRCTARGET $$DSTTARGET $$escape_expand(\\n\\t)
QMAKE_EXTRA_TARGETS += mybuild
PRE_TARGETDEPS += mybuild
