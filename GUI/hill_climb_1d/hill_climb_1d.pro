#-------------------------------------------------
#
# Project created by QtCreator 2014-10-16T21:13:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = hill_climb_1d
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11

INCLUDEPATH += "../common/"
INCLUDEPATH += "../common/qcustomplot"
INCLUDEPATH += "../../include/"
INCLUDEPATH += "../../randomSpace/"

SOURCES += main.cpp\
        mainwindow.cpp \
    ../common/openga_wrapper.cpp \
    ../common/qcustomplot/qcustomplot.cpp \
    ../../randomSpace/polySpace.cpp \
    ../../randomSpace/randomSpace.cpp \
    ../../src/rand.cpp

HEADERS  += mainwindow.h \
    ../common/openga_wrapper.h \
    ../common/qcustomplot/qcustomplot.h \
    ../../randomSpace/polySpace.hpp \
    ../../randomSpace/randomSpace.hpp \
    ../../include/rand.hpp

FORMS    += mainwindow.ui
