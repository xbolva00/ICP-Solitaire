#-------------------------------------------------
#
# Project created by QtCreator 2017-04-10T10:30:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gui
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        solitaire.cpp \
    ../board.cc \
    ../card.cc \
    ../card_deck.cc \
    ../card_stack.cc \
    ../command.cc \
    ../game.cc \
    ../hint.cc

HEADERS  += solitaire.h \
    ../board.h \
    ../card.h \
    ../card_deck.h \
    ../card_stack.h \
    ../command.h \
    ../game.h \
    ../hint.h

FORMS    += solitaire.ui
