#-------------------------------------------------
#
# Project created by QtCreator 2016-05-04T16:09:20 沙振宇
#
#-------------------------------------------------

QT       += core gui
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TCPClient
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    tcpclient.cpp

HEADERS  += mainwindow.h \
    tcpclient.h

FORMS    += mainwindow.ui
