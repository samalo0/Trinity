#-------------------------------------------------
#
# Project created by QtCreator 2015-04-14T15:00:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Trinity
TEMPLATE = app


SOURCES += main.cpp\
        trinity.cpp \
    setlist.cpp \
    RtMidi.cpp \
    midi.cpp \
    buttons.cpp

HEADERS  += trinity.h \
    setlist.h \
    RtMidi.h \
    midi.h \
    buttons.h

FORMS    += trinity.ui

RESOURCES += \
    images.qrc

win32 {
    LIBS += -lwinmm
    DEFINES += __WINDOWS_MM__
}

unix {
    LIBS += -lasound -lpthread -lwiringPi
    DEFINES += __LINUX_ALSA__
}
