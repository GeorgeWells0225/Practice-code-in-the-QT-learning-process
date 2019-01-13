#-------------------------------------------------
#
# Project created by QtCreator 2019-01-13T10:25:50
#
#-------------------------------------------------

QT       += core gui  //前面的QT为模块

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets //高于4版本添加 QT += widgets 兼容老版本
//应用程序名字
TARGET = 01_QtTest
//指定makefile的类型，app或lib（库）
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

SOURCES += \
        main.cpp \
        mywidget.cpp

HEADERS += \
        mywidget.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
