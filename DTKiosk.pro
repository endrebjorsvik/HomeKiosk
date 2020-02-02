#-------------------------------------------------
#
# Project created by QtCreator 2019-06-23T14:35:57
#
#-------------------------------------------------

QT       += core gui widgets xml positioning network svg

TARGET = DTKiosk
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++14

SOURCES += \
        main.cpp \
        mainwindow.cpp \
        yrforecast.cpp

HEADERS += \
        mainwindow.h \
        yrforecast.h

FORMS += \
        mainwindow.ui

#INCLUDEPATH += $${PWD}/gen/client
#DEPENDPATH += $${PWD}/gen/client
#include(gen/client/client.pri)

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    .gitignore \
    #gen/client/client.pri
