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
    ../../src/rand.cpp \
    hill_climb_1d.cpp \
    ../../src/population.cpp \
    ../../src/single_engine.cpp \
    ../../src/crossover.cpp \
    ../../src/dna.cpp \
    ../../src/engine.cpp \
    ../../src/individual.cpp \
    ../../src/individual_comp.cpp \
    ../../src/mutation.cpp \
    ../../src/simulation.cpp

HEADERS  += mainwindow.h \
    ../common/openga_wrapper.h \
    ../common/qcustomplot/qcustomplot.h \
    ../../randomSpace/polySpace.hpp \
    ../../randomSpace/randomSpace.hpp \
    ../../include/rand.hpp \
    hill_climb_1d.h \
    ../../include/openGA.hpp \
    ../../include/population.hpp \
    ../../include/single_engine.hpp \
    ../../include/crossover.hpp \
    ../../include/crossover_type.hpp \
    ../../include/dna.hpp \
    ../../include/engine.hpp \
    ../../include/engine_parameters.hpp \
    ../../include/error.hpp \
    ../../include/goals.hpp \
    ../../include/individual.hpp \
    ../../include/individual_comp.hpp \
    ../../include/mutation.hpp \
    ../../include/population_parameters.hpp \
    ../../include/selection_type.hpp \
    ../../include/simulation.hpp \
    ../../include/simulation_parameters.hpp

FORMS    += mainwindow.ui
