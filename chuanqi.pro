#-------------------------------------------------
#
# Project created by QtCreator 2018-11-10T15:49:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = chuanqi
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

INCLUDEPATH += \
        headers \
        sources \
        forms

SOURCES += \
        sources/main.cpp \
        sources/mainwindow.cpp \
        sources/gamemanager.cpp \
        sources/login.cpp \
        sources/logininfo.cpp \
        sources/addgame.cpp \
        sources/widgetnode.cpp \
        sources/downloadnode.cpp

HEADERS += \
    headers/mainwindow.h \
    headers/gamemanager.h \
    headers/login.h \
    headers/logininfo.h \
    headers/addgame.h \
    headers/widgetnode.h \
    headers/downloadnode.h

FORMS += \
        forms/mainwindow.ui \
        forms/gamemanager.ui \
        forms/login.ui \
        forms/logininfo.ui \
        forms/addgame.ui \
        forms/widgetnode.ui \
        forms/downloadnode.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    chuanqi.qrc

include(qzxing/QZXing.pri)
