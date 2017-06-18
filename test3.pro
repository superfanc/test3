#-------------------------------------------------
#
# Project created by QtCreator 2017-05-24T17:22:42
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    logindialog.cpp \
    insert.cpp \
    qupdate.cpp \
    qtdelete.cpp \
    qselect.cpp \
    adduser.cpp \
    userselect.cpp \
    userpsw.cpp

HEADERS  += mainwindow.h \
    logindialog.h \
    insert.h \
    qupdate.h \
    qtdelete.h \
    qselect.h \
    adduser.h \
    userselect.h \
    userpsw.h

FORMS    += mainwindow.ui \
    logindialog.ui \
    insert.ui \
    qupdate.ui \
    qtdelete.ui \
    qselect.ui \
    adduser.ui \
    userselect.ui \
    userpsw.ui

RESOURCES += \
    qss.qrc
