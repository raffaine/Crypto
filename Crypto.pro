#-------------------------------------------------
#
# Project created by QtCreator 2014-03-12T13:17:52
#
#-------------------------------------------------

QMAKE_CXXFLAGS += -std=c++0x

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Crypto
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    caesarcrypto.cpp \
    caesarshiftdialog.cpp \
    crazycaesar.cpp

HEADERS  += mainwindow.h \
    caesarcrypto.h \
    ICryptographer.h \
    caesarshiftdialog.h \
    crazycaesar.h

FORMS    += mainwindow.ui \
    caesarshiftdialog.ui
