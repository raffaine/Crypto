#-------------------------------------------------
#
# Project created by QtCreator 2014-03-12T13:17:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Crypto
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    caesarcrypto.cpp \
    caesarshiftdialog.cpp

HEADERS  += mainwindow.h \
    caesarcrypto.h \
    ICryptographer.h \
    caesarshiftdialog.h

FORMS    += mainwindow.ui \
    caesarshiftdialog.ui
