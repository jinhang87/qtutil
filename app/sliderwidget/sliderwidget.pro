QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sliderwidget
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

HEADERS += \
    BothWaySlider.h \
    SliderButton.h \
    SliderWidget.h \
    SliderWindow.h

SOURCES += \
    BothWaySlider.cpp \
    main.cpp \
    SliderButton.cpp \
    SliderWidget.cpp \
    SliderWindow.cpp

FORMS += \
    SliderWindow.ui
