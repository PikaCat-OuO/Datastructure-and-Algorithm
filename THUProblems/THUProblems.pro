TEMPLATE = app
CONFIG += console c++2a
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS_RELEASE += -O3
QMAKE_CXXFLAGS += -Werror
QMAKE_CXXFLAGS += -std=c++2a
SOURCES += \
    BoardCast.cpp \
    Cycle.cpp \
    Deduplicate.cpp \
    Temperature.cpp \
    Toy.cpp \
    binTree.cpp \
    lighthouse.cpp \
    range.cpp \
    schedule.cpp \
    temperature_lib.c \
    train.cpp \
    tsp.cpp \
    zuma.cpp

HEADERS += \
    temperature.h

