TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    player.cpp \
    gameboard.cpp \
    game.cpp

HEADERS += \
    player.h \
    gameboard.h \
    game.h
