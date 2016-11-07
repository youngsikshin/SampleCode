#-------------------------------------------------
#
# Project created by QtCreator 2016-11-07T22:52:57
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtGL
TEMPLATE = app


SOURCES += main.cpp\
        window.cpp \
    myglwidget.cpp

HEADERS  += window.h \
    myglwidget.h

FORMS    += window.ui
