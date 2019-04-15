#-------------------------------------------------
#
# Project created by QtCreator 2019-04-13T11:50:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
            chesswindow.cpp \
    Echecv4/Cavalier.cpp \
    Echecv4/Fou.cpp \
    Echecv4/main.cpp \
    Echecv4/pch.cpp \
    Echecv4/Piece.cpp \
    Echecv4/Pion.cpp \
    Echecv4/Reine.cpp \
    Echecv4/Roi.cpp \
    Echecv4/Tour.cpp \
    Echecv4/echecinterface.cpp

HEADERS += \
        chesswindow.h \
    Echecv4/Cavalier.h \
    Echecv4/Fou.h \
    Echecv4/pch.h \
    Echecv4/Piece.h \
    Echecv4/Pion.h \
    Echecv4/Reine.h \
    Echecv4/Roi.h \
    Echecv4/Tour.h \
    Echecv4/echecinterface.h

FORMS += \
        chesswindow.ui

RESOURCES += \
    resourcechess.qrc
