#-------------------------------------------------
#
# Project created by QtCreator 2018-03-26T15:28:36
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = distributeur
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialoglogin.cpp

HEADERS  += mainwindow.h \
    dialoglogin.h

FORMS    += mainwindow.ui \
    dialoglogin.ui
