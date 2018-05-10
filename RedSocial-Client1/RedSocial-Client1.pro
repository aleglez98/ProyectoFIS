TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += src/main.cpp \
        src/clientcontroller.cpp \
        src/socket.cpp \
        src/profile.cpp

HEADERS += \
    include/clientcontroller.h \
    include/profile.h \
    include/socket.h


