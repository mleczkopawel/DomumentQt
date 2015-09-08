#-------------------------------------------------
#
# Project created by QtCreator 2015-07-03T07:11:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DomumentQt
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cread.cpp \
    csave.cpp

HEADERS  += mainwindow.h \
    cread.h \
    csave.h

FORMS    += \
    mainwindow.ui

RESOURCES += \
    resource.qrc
win32: RC_ICONS = zmt.ico
