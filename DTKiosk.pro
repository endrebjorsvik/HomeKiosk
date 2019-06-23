#-------------------------------------------------
#
# Project created by QtCreator 2019-06-23T14:35:57
#
#-------------------------------------------------

QT       += core gui widgets

TARGET = DTKiosk
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        mainwindow.h

FORMS += \
        mainwindow.ui

INCLUDEPATH += $${PWD}/gen/client
DEPENDPATH += $${PWD}/gen/client

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
