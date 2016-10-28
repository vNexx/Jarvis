#-------------------------------------------------
#
# Project created by QtCreator 2016-10-23T00:55:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    smartdevice.cpp \
    smartbulb.cpp \
    dynamicbutton.cpp

HEADERS  += mainwindow.h \
    smartdevice.h \
    smartbulb.h \
    dynamicbutton.h

FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc
