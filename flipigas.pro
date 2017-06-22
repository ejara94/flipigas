#-------------------------------------------------
#
# Project created by QtCreator 2017-06-15T16:39:36
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = flipigas
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    secdialog.cpp \
    request_form.cpp \
    signin.cpp \
    dbmanager.cpp \
    table_request.cpp \
    truk.cpp

HEADERS  += mainwindow.h \
    secdialog.h \
    request_form.h \
    signin.h \
    dbmanager.h \
    table_request.h \
    truk.h

FORMS    += mainwindow.ui \
    secdialog.ui \
    request_form.ui \
    signin.ui \
    table_request.ui
