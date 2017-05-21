#-------------------------------------------------
#
# Project created by QtCreator 2011-07-06T15:47:27
#
#-------------------------------------------------

QT       += core gui \ opengl

TARGET = solido
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    glwidget.cpp

HEADERS  += mainwindow.h \
    offviewer.h \
    glwidget.h

LIBS += /usr/lib/libglut.so
